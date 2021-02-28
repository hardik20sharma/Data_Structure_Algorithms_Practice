/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

    For example, given n = 3, a solution set is:

    "((()))", "(()())", "(())()", "()(())", "()()()"
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

    For example, given n = 3, a solution set is:

    "((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int &n, string output = "", int open = 0, int close = 0)
{
    if(open == n && close == n)
    {
        cout << output << "\n";
        return;
    }

    if(open < n)
        solve(n, output + '(', open + 1, close);
    
    if(close < open && close < n)
        solve(n, output + ')', open, close + 1);
}

int main()
{
    int n = 5;
    solve(n);
}

/*
    n = 1
    ()

    n=2
    (())    ()()

    n = 3
    ((()))  (()())  (())()  ()()()
*/