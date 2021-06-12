/*
Input:
    N=6
    arr[] = {2, 1, 4, 7, 3, 6} 
Output: 12
    Explanation: Contiguous Increasing subarray {1, 4, 7} = 12.

Example 2:
Input:
    N=5
    arr[] = {38, 7, 8, 10, 12} 
Output: 38
*/

#include<bits/stdc++.h>
using namespace std;

int sol(vector<int> vec)
{
    int result = INT_MIN;
    vector<int> dp(vec.size());

    for(int i=1; i<dp.size(); i++)
    {
        int temp_max = INT_MIN;
        for(int j=0; j<i; j++)
            if(vec[j] <= vec[i])
                temp_max = max(temp_max, dp[j]);
        
        if(temp_max == INT_MIN)
            dp[i] = vec[i];
        else
            dp[i] = temp_max + vec[i];
        
        result = max(result, dp[i]);
    }

    return result;
}

int main()
{
    vector<int> vec{2, 1, 4, 7, 3, 5};
    cout << sol(vec);
}