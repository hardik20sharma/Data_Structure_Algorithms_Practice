#include<bits/stdc++.h>
using namespace std;

int sol(vector<int> vec, int i, int j, int k)
{
    
}

int main()
{
    vector<int> vec {1, 5, 15, 10}; int k = 3;

    sort(vec.begin(), vec.end());

    int min_height = vec[0], max_height = vec[vec.size()-1];

    int i = 0, j = vec.size()-1;

    
}

/*
    Given heights of n towers and a value k. We need to either increase or decrease height of every tower by k (only once) where k > 0. The task is to minimize the difference between the heights of the longest and the shortest tower after modifications, and output this difference.

Examples: 

Input  : arr[] = {1, 15, 10}, k = 6
Output :  Maximum difference is 2.
Explanation : We change 1 to 7, 15 to 9 and 10 to 4. Maximum difference is 5 (between 7 and 9). We can't get a lower difference.

Input : arr[] = {1, 5, 15, 10} k = 3
Output : Maximum difference is 8
arr[] = {4, 8, 12, 7}

Input : arr[] = {4, 6} k = 10
Output : Maximum difference is 2
arr[] = {14, 16} OR {-6, -4}

Input : arr[] = {6, 10} k = 3
Output : Maximum difference is 2
arr[] = {9, 7}

Input : arr[] = {1, 10, 14, 14, 14, 15} k = 6
Output: Maximum difference is 5
arr[] = {7, 4, 8, 8, 8, 9} 

Input : arr[] = {1, 2, 3} k = 2
Output: Maximum difference is 2
arr[] = {3, 4, 5}

*/