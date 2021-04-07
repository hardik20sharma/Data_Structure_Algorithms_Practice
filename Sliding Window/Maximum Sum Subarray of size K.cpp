/*
    Given an array of integers Arr of size N and a number K. Return the max sum of a subarray of size K.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec {100, 300, 200, 400};
    int k = 2, n = vec.size();

    int i = 0, j = 0, sum_in_window = 0, res = 0;
    
    while(j < n)
    {
        sum_in_window += vec[j];

        if(j - i + 1 < k)
            j++;

        else if(j - i + 1 == k)
        {
            res = max(sum_in_window, res);
            sum_in_window -= vec[i];
            
            i++; j++;
        }
    }

    cout << res << "\n";
}