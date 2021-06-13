/*
    Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 

    Examples: 

    arr[] = {1, 5, 11, 5}
    Output: true 
    The array can be partitioned as {1, 5, 5} and {11}

    arr[] = {1, 5, 3}
    Output: false 
    The array cannot be partitioned into equal sum sets.
*/

#include<bits/stdc++.h>
using namespace std;

bool func(int arr[], int n, int sum)    // Same function as subset sum problem
{
    bool DP_Matrix[n+1][sum+1];

    // Base case, when sum == 0
    for(int i=0; i<=n; i++)
        DP_Matrix[i][0] = true;

    // Base case, when n == 0
    for(int j=1; j<=sum; j++)
        DP_Matrix[0][j] = false;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=sum; j++)
            if(j < arr[i-1])
                DP_Matrix[i][j] = DP_Matrix[i-1][j];
            else
                DP_Matrix[i][j] = DP_Matrix[i-1][j] || DP_Matrix[i-1][j-arr[i-1]];

    // Printing the DP_Matrix
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
            cout << DP_Matrix[i][j] << " ";
        cout << "\n";
    }

    return DP_Matrix[n][sum];
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    if(sum & 1)         // If sum of the array is odd, equal partition won't be possible
        cout << "0";
    else                // If sum of the array is even, we need to find subset with sum s/2
        cout << func(arr, n, sum/2);
}