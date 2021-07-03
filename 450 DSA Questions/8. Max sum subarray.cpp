#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec {1, 2, 3, 4, 5, -10, 100};

    int i = 0, j = 0, result = INT_MIN, sum_in_subarray = 0;

    while(j < vec.size())
    {
        sum_in_subarray += vec[j];
        j++;

        result = max(result, sum_in_subarray);

        while(i < j && sum_in_subarray < sum_in_subarray - vec[i])
        {
            sum_in_subarray = sum_in_subarray - vec[i];
            i++;
        }

        result = max(result, sum_in_subarray);
    }

    cout << result << "\n";
}