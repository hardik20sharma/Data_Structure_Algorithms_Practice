// 10.Given an array with all distinct elements, find the largest three elements. Expected time complexity is O(n) and extra space is O(1).Input: arr[] = {10, 4, 3, 50, 23, 90}Output: 90, 50, 23
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{1,2,3,4,5,6,7,8,9,1,2,3,4};
    int first = -1, second = -1, third = -1;

    for(int i=0; i<a.size(); i++)
        if(first < a[i])
        {
            third = second;
            second = first;
            first = a[i];
        }
        else if(second < a[i])
        {
            third = second;
            second = a[i];
        }
        else if(third < a[i])
            third = a[i];

    cout << first << " " << second << " " << third;
}