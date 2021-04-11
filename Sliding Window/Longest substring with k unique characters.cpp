/*
    Given a string you need to print the size of the longest possible substring that has exactly k unique characters.

    Example:
    Input:
        2
        aabacbebebe
        3
        aaaa
        1
    Output:
        7
        4
*/

#include<bits/stdc++.h>
using namespace std;

int sol(string s, int req_unique_char)
{
    vector<int> letters(26, 0);
    int unique_char_count = 0, i = 0, j = 0, max_len = 0;

    while(j < s.size())
        if(unique_char_count < req_unique_char)
        {
            if(letters[ s[j]-'a' ] == 0)
                unique_char_count++;
            letters[ s[j]-'a' ]++;

            j++;
        }
        else if(unique_char_count == req_unique_char)
        {
            max_len = max(max_len, j-i+1);

            j++;

            if(letters[ s[j]-'a' ] == 0)
                unique_char_count++;
            letters[ s[j]-'a' ]++;
        }
        else if(unique_char_count > req_unique_char)
        {
            if(letters[ s[i]-'a' ] == 1)
                unique_char_count--;            
            letters[ s[i]-'a' ]--;

            i++;
        }
    
    return max_len;
}

int main()
{
    string s = "aabacbebebe";
    int req_unique_char = 10;

    cout << sol(s, req_unique_char);
}