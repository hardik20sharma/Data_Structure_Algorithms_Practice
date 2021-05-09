/*
    Evaluate Expression To True-Boolean Parenthesization Recursion - Memoization
    Given a boolean expression with following symbols.
    Symbols
        'T' --- true 
        'F' --- false 
    And following operators filled between symbols
    Operators
        &   ---boolean AND
        |   --- boolean OR
        ^   --- boolean XOR 
    Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
    
    Example:
    Input:  symbol[]    = {T, F, T}
            operator[]  = {^, &}
    Output: 2
    The given expression is "T ^ F & T", it evaluates true in two ways "((T ^ F) & T)" and "(T ^ (F & T))"
*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> hash_map;

string Generate_Key(int i, int j, bool to_find)
{
    return to_string(i) + " " + to_string(j) + " " + to_string(to_find);
}

int Evaluate_Expression(string s, int i, int j, bool to_find)
{
    if(j < i)       // Base condition
        return 0;

    string curr = Generate_Key(i, j, to_find);
    if(hash_map.find(curr) != hash_map.end())
        return hash_map[curr];

    if(i == j)      // Base condition
        if(to_find)                 // Checkes if we want to evaluate expression to true or false
            return hash_map[curr] = s[i] == 'T';     // Returns 1 when expression is 'T' and required is true else 0
        else
            return hash_map[curr] = s[i] == 'F';     // Returns 1 when expression is 'F' and required is false else 0

    int ans = 0;
    for(int k=i+1; k<j; k+=2)
    {
        int left_true, left_false, right_true, right_false;
        
        string LT = Generate_Key(i, k-1, true);
        string LF = Generate_Key(i, k-1, false);
        string RT = Generate_Key(k+1, j, true);
        string RF = Generate_Key(k+1, j, false);
        
        if(hash_map.find(LT) != hash_map.end())
            left_true = hash_map[LT];
        else
        {
            left_true = Evaluate_Expression(s, i, k-1, true);
            hash_map[LT] = left_true;
        }

        if(hash_map.find(LF) != hash_map.end())
            left_false = hash_map[LF];
        else
        {
            left_false = Evaluate_Expression(s, i, k-1, false);
            hash_map[LF] = left_false;
        }


        if(hash_map.find(RT) != hash_map.end())
            right_true = hash_map[RT];
        else
        {
            right_true = Evaluate_Expression(s, k+1, j, true);
            hash_map[RT] = right_true;
        }

        if(hash_map.find(RF) != hash_map.end())
            right_false = hash_map[RF];
        else
        {
            right_false = Evaluate_Expression(s, k+1, j, false);
            hash_map[RF] = right_false;
        }


        if(s[k] == '&')     // When operator is &   -- Case 1
            if(to_find)     // When we need to find number of times expression becomes true
                ans += (left_true * right_true);
            else            // When we need to find number of times expression becomes false
                ans += (left_true * right_false) + (left_false * right_true) + (left_false * right_false);

        else if(s[k] == '|')     // When operator is |   -- Case 2
            if(to_find)     // When we need to find number of times expression becomes true
                ans += (left_true * right_true) + (left_true * right_false) + (left_false * right_true);
            else            // When we need to find number of times expression becomes false
                ans += (left_false * right_false);

        else if(s[k] == '^')     // When operator is ^   -- Case 3
            if(to_find)     // When we need to find number of times expression becomes true
                ans += (left_true * right_false) + (left_false * right_true);
            else            // When we need to find number of times expression becomes false
                ans += (left_false * right_false) + (right_false * right_true);
    }

    return hash_map[curr] = ans;
}

int main()
{
    string s = "T^T^T^F|F&F^F|T^F^T";
    cout << Evaluate_Expression(s, 0, s.size()-1, true);
}