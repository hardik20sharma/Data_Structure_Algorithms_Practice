/*
Egg Dropping using Recursion

    Problem statement: You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

    If egg breaks at ith floor then it also breaks at all greater floors.
    If egg does not break at ith floor then it does not break at all lower floors.
    Unbroken egg can be used again.
    Note: You have to find minimum trials required to find the critical floor not the critical floor.

    Example:
    Input:
        4   --  N floor
        2   --  K eggs
        
        Output:
        Number of trials when number of eggs is 2 and number of floors is 4: 3
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> DP;

int Egg_Drop(int eggs, int floors)
{
    if(DP[eggs][floors] != -1)
        return DP[eggs][floors];

    // When number of eggs is only 1, we will be greedy about our approach and go upto f floors
    // When no of floor is 0 or 1, then min trial is f (0 or 1)
    if(floors <= 1 || eggs == 1)
        return DP[eggs][floors] = floors; 

    
    int result = INT_MAX;
    for(int k=1; k<=floors; k++)
    {
        int temp_ans_part_1, temp_ans_part_2;

        if(DP[eggs-1][k-1] != -1)
            temp_ans_part_1 = DP[eggs-1][k-1];
        else
        {
            temp_ans_part_1 = Egg_Drop(eggs-1, k-1);
            DP[eggs-1][k-1] = temp_ans_part_1;
        }

        if(DP[eggs][floors-k] != -1)
            temp_ans_part_2 = DP[eggs][floors-k];
        else
        {
            temp_ans_part_2 = Egg_Drop(eggs, floors-k);
            DP[eggs][floors-k] = temp_ans_part_2;
        }

        int temp_ans = 1 + max(temp_ans_part_1, temp_ans_part_2);   // Writing max because its worst case
        result = min(result, temp_ans);     // Writing min because we need to find min number of attempts
    }

    return DP[eggs][floors] = result;
}

int main()
{
    int eggs = 1104252, floors = 15572;
    DP.resize(eggs+1, vector<int>(floors+1, -1));
    cout << Egg_Drop(eggs, floors);
}