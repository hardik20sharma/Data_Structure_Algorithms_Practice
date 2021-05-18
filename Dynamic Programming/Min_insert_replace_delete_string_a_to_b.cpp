/*
    Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

    1. Insert
    2. Remove
    3. Replace
    All of the above operations are of equal cost.

    Examples:

    Input:   str1 = "geek", str2 = "gesek"
    Output:  1
    We can convert str1 into str2 by inserting a 's'.

    Input:   str1 = "cat", str2 = "cut"
    Output:  1
    We can convert str1 into str2 by replacing 'a' with 'u'.

    Input:   str1 = "sunday", str2 = "saturday"
    Output:  3
    Last three and first characters are same.  We basically need to convert "un" to "atur".  This can be done using below three operations. Replace 'n' with 'r', insert t, insert a
*/

#include<bits/stdc++.h>
using namespace std;

// NOTE: WE CAN ONLY PERFORM OPERATIONS ON STRING 1

int min_no_of_deletions_insertions_replace(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int DP[ n+1 ][ m+1 ];

    for(int i=0; i<=n; i++)     // When string 1 is empty, only option is insert all elements in it
        DP[i][0] = i;
    for(int j=0; j<=m; j++)     // When string 2 is empty, only option is delete all elements from string 1
        DP[0][j] = j;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(s1[i-1] == s2[j-1])
                DP[i][j] = DP[i-1][j-1];    // When character is matched, no operations needs to be done
            else
                DP[i][j] = 1 + min(DP[i-1][j-1],    // Replace
                                min(DP[i-1][j],     // Remove
                                    DP[i][j-1]));   // Insert
    return DP[n][m];
}

int main()
{
    string s1 = "sunday", s2 = "saturday";

    cout << min_no_of_deletions_insertions_replace(s1, s2) << "\n";
}