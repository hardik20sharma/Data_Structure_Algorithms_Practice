/*
    Coin Change Problem Minimum Numbers of coins
    
    Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
    Example:

    Input: coins[] = {25, 10, 5}, V = 30
    Output: Minimum 2 coins required
    We can use one coin of 25 cents and one of 5 cents 
*/

#include<bits/stdc++.h>
using namespace std;

int min_no_of_coins (int coins[], int n, int value)
{
    int DP[ n+1 ][ value+1 ];

    for(int j=0; j<=value; j++)     // Initialize i=0, j from 0 to values, INT_MAX
        DP[0][j] = INT_MAX-1;

    for(int i=1; i<=n; i++)         // Initialize j=0, i from 1 to n, 0
        DP[i][0]  = 0;
    
    for(int j=1; j<=value; j++)     // Initializing second row of table, if sum is divisible by 1st coin, well and good else INT_MAX
        if(j % coins[0] == 0)
            DP[1][j] = j/coins[0];
        else
            DP[1][j] = INT_MAX-1;

    for(int i=2; i<=n; i++)
        for(int j=1; j<=value; j++)
            if(j < coins[i-1])
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = min( DP[i-1][j], 1 + DP[i][ j - coins[i-1] ] );

    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=value; j++)
    //         cout << DP[i][j] << " ";
    //     cout << endl;
    // }

    return DP[n][value];
}

int main()
{
    int coins[] = {25, 10, 5};
    int value = 30;

    int n = sizeof(coins) / sizeof(coins[0]);

    cout << min_no_of_coins(coins, n, value);
}