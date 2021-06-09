/*
    Longest Palindromic Subsequence
    Given a sequence, find the length of the longest palindromic subsequence in it.
    
    Example :
    Input:"bbbab"
    Output:4

        b   b   b   a   b
        b   a   b   b   b

        b   b   b   b
*/

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int DP[n+1][m+1];

    for(int i=0; i<=n; i++)     // Base condition - string s1 is empty
        DP[i][0] = 0;
    for(int j=0; j<=m; j++)     // Base condition - string s2 is empty
        DP[0][j] = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(s1[i-1] == s2[j-1])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i][j-1], DP[i-1][j]);

    for(int i=0; i<=n; i++, cout << endl)
        for(int j=0; j<=m; j++)
            cout << DP[i][j] << " ";

    // for(int i=n, j=n; i>0 && j>0; )
    // {
    //     if(dp[i][j] == dp[i-1][j-1] + 1)
    // }

    return DP[n][m];
}

int length_of_longest_palindromic_sequence(string s)
{
    string reverse_s = string(s.rbegin(), s.rend());
    return lcs(s, reverse_s);
}

int main()
{
    string s = "ccd";
    cout << length_of_longest_palindromic_sequence(s);
}