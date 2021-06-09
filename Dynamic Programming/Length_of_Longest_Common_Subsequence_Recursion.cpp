/*

    Longest Common Subsequence Problem solution using recursion
    Given two sequences, find the length of longest subsequence present in both of them.
    A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 

    For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

*/

#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequences(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    if(n == 0 || m == 0)        // Base condition
        return 0;

    else if(s1[n-1] == s2[m-1]) // When character is matched, decrease length of both strings
        return 1 + longest_common_subsequences( s1.substr(0, n-1), s2.substr(0, m-1) );

    // Decrease length from string 1, then from string 2...out of them return the max
    return max( longest_common_subsequences( s1.substr(0, n-1), s2.substr(0, m) ), 
                longest_common_subsequences( s1.substr(0, n), s2.substr(0, m-1) )
    );
}

int main()
{
    string s1 = "kayla";
    string s2 = "jayla";

    cout << longest_common_subsequences(s1, s2);
}