/*
    Given a number N, generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit. 
    
    Input:      N = 2
    Output:     00 01 11 10
    
    Input:      N=3
    Output:     000 001 011 010 110 111 101 100
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> graycode(int n)
{
    if(n == 1)
        return {"0", "1"};
    
    vector<string> prev_ans = graycode(n - 1);
    vector<string> ans;
    
    for(string s : prev_ans)
        ans.push_back('0' + s);
    
    for(int i = prev_ans.size() - 1; i >= 0; i--)
        ans.push_back('1' + prev_ans[i]);
    
    return ans;
}

int main()
{
    int n = 5;
    vector<string> res = graycode(n);

    for(string s : res)
        cout << s << " ";
}