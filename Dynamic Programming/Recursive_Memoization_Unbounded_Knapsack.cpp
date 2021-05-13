/*

    Unbounded Knapsack (Repetition of items allowed)
    Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate minimum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number  of instances of an item.
    
    Examples:

    Input : W = 100
        val[]  = {1, 30}
        wt[] = {1, 50}
    Output : 100
    
    There are many ways to fill knapsack.
    1) 2 instances of 50 unit weight item.
    2) 100 instances of 1 unit weight item.
    3) 1 instance of 50 unit weight item and 50
    instances of 1 unit weight items.
    We get maximum value with option 2.

*/

#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:
    int val, weight;
    Item(int val1, int val2) : val(val1), weight(val2) {}
};

vector<vector<int>> DP;

int recursive_unbounded_knapsack(Item items[], int n, int capacity)
{
    if(n == 0 || capacity == 0)     // Base condition
        return 0;
    
    if(DP[n][capacity] != -1)       // If value is already present, use it
        return DP[n][capacity];

    if(capacity < items[n-1].weight)    // If capacity is less than item weight, leave it
        return DP[n][capacity] = recursive_unbounded_knapsack(items, n-1, capacity);
    
    // value when item is included, repetition is allowed
    int with_element = items[n-1].val + recursive_unbounded_knapsack(items, n, capacity - items[n-1].weight);

    // value when item is not included, when not included, we can move ahead without thinking anything
    int without_element = recursive_unbounded_knapsack(items, n-1, capacity);

    return DP[n][capacity] = max(with_element, without_element);
}

int main()
{
    Item items[] = { {1, 1}, {30, 50} };
    int capacity = 100;
    
    int n = sizeof(items) / sizeof(items[0]);

    DP.resize(n+1, vector<int> (capacity+1, -1) );

    cout << recursive_unbounded_knapsack(items, n, capacity);
}