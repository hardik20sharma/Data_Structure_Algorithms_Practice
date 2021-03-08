/*
    The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
*/

#include<bits/stdc++.h>
using namespace std;

static int cnt_steps;

void solve(int n, int source, int helper, int destination)
{
    cnt_steps++;
    if(n == 1)
    {
        cout << source << " to " << destination << "\n";
        return;
    }
    
    solve(n-1, source, destination, helper);        // Place the n-1 disks from source to helper
    cout << source << " to " << destination << "\n";

    solve(n-1, helper, source, destination);        // Place the largest disk in destination
    return;
}

int main()
{
    int n = 3, source_rod = 1, helper_rod = 2, desination_rod = 3;
    cnt_steps = 0;
    cout << "\n";
    solve(n, source_rod, helper_rod, desination_rod);
    cout << "\nTotal steps: " << cnt_steps << "\n\n";
}