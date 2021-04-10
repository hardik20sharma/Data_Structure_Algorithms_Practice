/*
    Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

    Example:

    Input:
    5 2
    -8 2 3 -6 10

    Output:
    -8 0 -6 -6
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec {12, -1, -7, 8, -15, 30, 16, 28};
    int n = vec.size(), k = 3;

    int i = 0, j = 0;
    queue<int> q;
    
    while(j < n)
        if(j - i + 1 < k)
        {
            if(vec[j] < 0)
                q.push(vec[j]);
            j++;
        }
        else if(j - i + 1 == k)
        {
            if(vec[j] < 0)
                q.push(vec[j]);

            (q.empty()) ? cout << "0 " : cout << q.front() << " ";

            if(q.front() == vec[i])
                q.pop();

            i++;
            j++;
        }
}