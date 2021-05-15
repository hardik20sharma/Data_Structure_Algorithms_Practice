/*
    0-1 Knapsack Problem solution using recursion(Overlapping Subproblems).

    Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

    Uses no memoization
*/

#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:

    int value, weight;
    Item(int input_1, int input_2) : value (input_1), weight (input_2) {}
};

int Knapsack_func(Item items[], int n, int max_weight)
{
    if(n == 0 || max_weight == 0)
        return 0;

    if(items[n-1].weight > max_weight)
        return Knapsack_func(items, n-1, max_weight);

    int with_element = items[n-1].value + Knapsack_func(items, n-1, max_weight - items[n-1].weight);
    int without_element = Knapsack_func(items, n-1, max_weight);

    return max( with_element, without_element );
}

int main()
{
    int max_weight = 50;

    Item items[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(items) / sizeof(items[0]);

    cout << Knapsack_func(items, n, max_weight);
}