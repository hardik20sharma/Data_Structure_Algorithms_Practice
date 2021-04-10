/*
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
*/

#include<bits/stdc++.h>
using namespace std;

int sol(string s, string t)
{
    int min_len = INT_MAX, i = 0, j = 0;
    bool possible;

    map<char, int> req_mp, mp;

    for(char c : t)
        req_mp[c]++;

    while(j <= s.size())
    {
        possible = true;

        for(char c : t)
            if(req_mp[c] > mp[c])
                possible = false;

        if(possible)
        {
            min_len = min(min_len, j-i);
            mp[s[i]]--;
            i++;
        }
        else
        {
            mp[s[j]]++;
            j++;
        }
    }

    return min_len;
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << sol(s, t);
}