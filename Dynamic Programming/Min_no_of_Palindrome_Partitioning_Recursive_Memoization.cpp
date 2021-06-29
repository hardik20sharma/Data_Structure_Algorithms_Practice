/*
    Palindrome Partitioning using Recursion and memoization - min number of partition
    
    Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
*/

#include<bits/stdc++.h>
using namespace std;

bool is_Palindrome(string s, int i, int j)
{
    for( ; i<j; i++, j--)
        if(s[i] != s[j])
            return false;
    return true;
}

vector<vector<int>> DP;

int Palindrome_Partition(string s, int i, int j)
{
    // If string is empty or has only one character, number of partitions will be zero
    // If string is already palindrome, partition isn't required, so number of partitions is zero

    if(j <= i)     // Base condition
        return DP[i][j] = 0;

    if(DP[i][j] != -1)
        return DP[i][j];

    if(is_Palindrome(s, i, j))
        return DP[i][j] = 0;

    int result = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp_ans, temp_ans_part_1, temp_ans_part_2;

        // Check if value of left partition is already present in table or not
        if(DP[i][k] != -1)
            temp_ans_part_1 = DP[i][k];
        else
        {
            temp_ans_part_1 = Palindrome_Partition(s, i, k);
            DP[i][k] = temp_ans_part_1;
        }

        // Check if value of right partition is already present in table or not
        if(DP[k+1][j] != -1)
            temp_ans_part_2 = DP[k+1][j];
        else
        {
            temp_ans_part_2 = Palindrome_Partition(s, k+1, j);
            DP[k+1][j] = temp_ans_part_2;
        }

        temp_ans = 1 + temp_ans_part_1 + temp_ans_part_2;
        result = min(result, temp_ans);
    }

    return DP[i][j] = result;
}

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    DP.resize(s.size(), vector<int>(s.size(), -1));

    cout << Palindrome_Partition(s, 0, s.size()-1);
}

/*
    Example:    “a|babbbab|b|ababa” is a palindrome partitioning of “ababbbabbababa”.
*/