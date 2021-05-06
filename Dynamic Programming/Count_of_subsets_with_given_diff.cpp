/*
    Count the number of subset with a given difference

    Input: {1, 1, 2, 3}
    Difference: 1
    Output: 3   
    
    1+3 and 1+2     1+1+2 and 3     1+3 and 1+2

    This problem can be reduced to subset sum problem
    
    S2 - S1 = diff
    Sum - 2S1 = diff
    S1 = (Sum - diff)/2;
*/

#include<bits/stdc++.h>
using namespace std;

int subset_sum(int arr[], int n, int sum)
{
    int DP[n+1][sum+1];

    for(int i=0; i<=n; i++)
        DP[i][0] = 1;
    
    for(int j=1; j<=sum; j++)
        DP[0][j] = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=sum; j++)
            if(j < arr[i-1])
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = DP[i-1][j] + DP[i-1][j-arr[i-1]];
    
    return DP[n][sum];
}

int count_no_subset_with_given_diff(int arr[], int n, int diff)
{
    int sum = 0;
    for(int i=0; i<n; i++)  // Finding the total sum of array
        sum += arr[i];
    
    int s1 = (sum - diff) / 2;  // Required subset sum

    return subset_sum(arr, n, s1);
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int difference = 1;

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << count_no_subset_with_given_diff(arr, n, difference);
}