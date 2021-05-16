/*
    Longest Common Subsequence Problem solution using Memoization
    Given two sequences, find the length of longest subsequence present in both of them.
    A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 

    For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.
*/

#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequences_bottom_up(string s1, string s2)
{
    int n = s1.size(), m = s2.size();   // n = size of string 1     m = size of string 2
    int DP[ n+1 ][ m+1 ];               // Creating DP table

    for(int i=0; i<=n; i++)     // Base condition, when n=0, no such string will be possible
        DP[i][0] = 0;
    for(int j=0; j<=m; j++)     // Base condition, when m=0, no such string will be possible
        DP[0][j] = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if( s1[i-1] == s2[j-1] )
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);

    return DP[n][m];
}

int main()
{
    string s1 = "abcde";
    string s2 = "cdefg";

    cout << longest_common_subsequences_bottom_up(s1, s2);
}