/*
    Minimum number of deletions to make a string palindrome
    Same as
    Minimum number of insertion to make a string palindrome
    
    Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
    
    Examples :
    Input : aebcbda
    Output : 2
    
    Remove characters 'e' and 'd' Resultant string will be 'abcba' which is a palindromic string

    a   e   b   c   b   d   a   -- string s
    a   d   b   c   b   e   a   -- revere it

    a   b   c   b   a   -- apply lcs on it
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int DP[n+1][m+1];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            if(i == 0 || j == 0)        // Base case
                DP[i][j] = 0;
            else if(s1[i-1] == s2[j-1])     // When charcter is matched
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);     // When character is unmatched

    return DP[n][m];
}

int min_deletion_make_string_palindrome(string s)
{
    string s_rev = string(s.rbegin(), s.rend());
    return s.size() - LCS(s, s_rev);
}

int main()
{
    string s = "eaabcbaaa";
    cout << min_deletion_make_string_palindrome(s);
}