/*
    Given a string s, find the length of the longest substring without repeating characters.

    Example:
        Input: s = "pwwkew"
    Output: 3
        Explanation: The answer is "wke", with the length of 3.
        Notice that the answer must be a substring, "pwke" is a subsequence and not a substring
*/

#include<bits/stdc++.h>
using namespace std;

int sol(string s)
{
    vector<int> letters(26, 0);
    int unique_char = 1, i = 0, j = 0, max_len = 0;

    while(j <= s.size())
        if(j-i+1 == unique_char)
        {
            max_len = max(max_len, unique_char);

            if(letters[ s[j]-'a' ] == 0)
                unique_char++;
            letters[ s[j]-'a' ]++;

            j++;
        }
        else if(j-i+1 > unique_char)
        {
            if(letters[ s[i]-'a' ] == 1)
                unique_char--;
            letters[ s[i]-'a' ]--;

            i++;
        }

    return max_len-1;
}

int main()
{
    string s = "pwwkew";
    cout << sol(s);
}