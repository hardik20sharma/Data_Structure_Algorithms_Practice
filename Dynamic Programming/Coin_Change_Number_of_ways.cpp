/*
    Coin Change Problem Maximum Number of ways
    Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
    Example:
    for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.
*/

#include<bits/stdc++.h>
using namespace std;

int unbounded_subset_sum (int coins[], int n, int sum)
{
    int DP[n + 1][sum + 1];

    for(int i=0; i<=n; i++)      // For sum 0, any number of coins won't matter, choice is : giving nothing
        DP[i][0] = 1;

    for(int j=1; j<=sum; j++)   // For number of coins 0, sum won't matter as its gonna be impossible to achieve the required sum
        DP[0][j] = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=sum; j++)
            if(j < coins[i-1])
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = DP[i-1][j] + DP[i][ j - coins[i-1] ];
    
    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=sum; j++)
    //         cout << DP[i][j] << " ";
    //     cout << endl;
    // }

    return DP[n][sum];
}

int main()
{
    int coins[] = {1, 2, 3};
    int total = 5;

    int n = sizeof(coins) / sizeof(coins[0]);

    cout << unbounded_subset_sum(coins, n, total);
}