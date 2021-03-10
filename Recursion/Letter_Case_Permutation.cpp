/*
    Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

    Examples:
    Input: S = "a1b2"
    Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

    Input: S = "3z4"
    Output: ["3z4", "3Z4"]

    Input: S = "12345"
    Output: ["12345"]
*/
#include<bits/stdc++.h>
using namespace std;

void solve(string input, string output="")
{
    if(input == "")     // Base condition
    {
        cout << output << " ";
        return;
    }

    string output1 = output;        // Initial output added in output1

    // --- If lowercase, make it uppercase ---
    ('a' <= input[0] && input[0] <= 'z') ? output1 += (input[0] - 'a' + 'A') : output1 += input[0];

    string output2 = output + input[0];     // Initial output added in output2

    input = input.substr(1);    // Removing first character from input

    solve(input, output1);  // Case of uppercase
    
    if(output1 != output2)
        solve(input, output2);      // Case of lowercase
}

int main()
{
    string s = "a1b2c3";
    solve(s);
}