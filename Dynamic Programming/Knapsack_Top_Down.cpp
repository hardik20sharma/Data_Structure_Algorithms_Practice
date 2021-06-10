/*
    0-1 Knapsack Problem solution using recursion(Overlapping Subproblems).

    Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

    Uses memoization and top down approach, not using recursion
*/

#include<bits/stdc++.h>
using namespace std;

class Item  // Item class, holds value and weight of the item
{
public:
    int value, weight;
    Item(int input_1, int input_2) : value (input_1), weight (input_2) {}
};

int Knapsack_func(Item items[], int n, int max_weight)      // Finds the max value with min number of weights
{
    vector <vector<int>> DP_Matrix( n+1, vector<int> (max_weight + 1, 0) );

    for(int i=1; i<=n; i++)
        for(int j=1; j<=max_weight; j++)
            if( items[i-1].weight <= j )
                DP_Matrix[i][j] = max( items[i-1].value + DP_Matrix[i-1][j - items[i-1].weight], 
                                        DP_Matrix[i-1][j]);
            else
                DP_Matrix[i][j] = DP_Matrix[i-1][j];

    for(int i=0; i<=n; i++, cout << "\n")
        for(int j=0; j<=max_weight; j++)
                cout << DP_Matrix[i][j] << " ";

    return DP_Matrix[n][max_weight];
}

int main()
{
    int max_weight = 11;    // Max weight of knapsack
    Item items[] = { {1, 1}, {6, 2}, {18, 5}, {22, 6}, {28, 7} };
    int n = sizeof(items) / sizeof(items[0]);

    cout << Knapsack_func(items, n, max_weight);
}