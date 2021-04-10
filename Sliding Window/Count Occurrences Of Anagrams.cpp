/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:
    Input: txt = forxxorfxdofr      pat = for
    Output: 3
    Explanation: for, orf and ofr appears in the txt, hence answer is 3.

Example 2:
    Input: txt = aabaabaa       pat = aaba
    Output: 4
    Explanation: aaba is present 4 times in txt.
*/

#include<bits/stdc++.h>
using namespace std;

bool is_Count_Zero(vector<int> &letter_count)       // Check if count of all letters is 0 or not
{
    for(int i : letter_count)
        if(i)
            return false;
    return true;
}

int sol(string text, string pattern)        // Solution function
{
    int result = 0, text_size = text.size(), pattern_size = pattern.size();

    vector<int> letter_count (26, 0);   // stores the frequency of each letter

    for(int i=0; i < pattern_size; i++)     // For the first window
    {
        letter_count[ text[i] - 'a']++;     // Increase the count of letters in text string
        letter_count[ pattern[i] - 'a']--;  // Decrease the count of letters in pattern string
    }

    if(is_Count_Zero(letter_count))     // Check if the first window is valid itself or not
        result++;
    
    for(int i = pattern_size; i < text_size; i++)       // Moving the window now
    {
        letter_count[text[i] - 'a']++;                  // Increase the count of letter for new character
        letter_count[text[i - pattern_size] - 'a']--; // Decrease the count of letter for prev character

        if(is_Count_Zero(letter_count))     // Check if the window is valid or not
            result++;
    }
    return result;
}

int main()
{
    string text = "aabaabaa", pattern = "aaba";
    cout << sol(text, pattern);
}