/*
Problem Description:
    Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 4
*/

#include<bits/stdc++.h>
using namespace std;

int sol(vector<int> vec, int sum)
{
    int i = 0, j = 0, sub_array_sum = 0, max_len = 0;

    while(j < vec.size())           // While j doesn't reach end
        if(sub_array_sum < sum)         // If sum in subarray is smaller than sum, add another value
        {
            sub_array_sum += vec[j];
            j++;
        }

        else if(sub_array_sum == sum)       // When subarray sum is equal to required sum, do a max length, increase the size by one
        {
            max_len = max(max_len, j-i);
            sub_array_sum += vec[j];
            j++;
        }

        else if(sub_array_sum > sum)        // When subarray sum is greater than required sum, we need to pop elements in subarray
        {
            sub_array_sum -= vec[i];
            i++;
        }

    return max_len;     // Returning max length of subarray sum
}

int main()
{
    vector<int> vec {4, 1, 1, 1, 2, 3, 5};
    int sum = 100;

    cout << sol(vec, sum);
}
