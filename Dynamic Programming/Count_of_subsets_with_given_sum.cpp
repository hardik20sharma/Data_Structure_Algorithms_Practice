/*
    Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

    Examples:

    Input: arr[] = {1, 2, 3, 3}, X = 6
    Output: 3
    All the possible subsets are {1, 2, 3}, {1, 2, 3} and {3, 3}

    Input: arr[] = {1, 1, 1, 1}, X = 1
    Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

int func(int arr[], int n, int sum)
{
    int DP_Matrix[n+1][sum+1];

    for(int i=0; i<=n; i++)
        DP_Matrix[i][0] = 1;

    for(int j=1; j<=sum; j++)
        DP_Matrix[0][j] = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=sum; j++)
            if(j < arr[i-1])
                DP_Matrix[i][j] = DP_Matrix[i-1][j];
            else
                DP_Matrix[i][j] = DP_Matrix[i-1][j] + DP_Matrix[i-1][j-arr[i-1]];

    return DP_Matrix[n][sum];
}

int main()
{
    int arr[] = {1, 2, 3, 3};
    int sum = 6;

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << func(arr, n, sum);
}