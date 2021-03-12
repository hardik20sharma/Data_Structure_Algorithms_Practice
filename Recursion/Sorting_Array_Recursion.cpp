/*
    Sorting and array using Recursion by using Induction-Hypothesis and Base condition Approach.
*/

#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int &temp)
{
    if(v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    
    int last_element = v[v.size() - 1];
    v.pop_back();
    insert(v, temp);
    v.push_back(last_element);
}

void sort(vector<int> &v)
{
    if(v.size() == 1)
        return;
    
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v, temp);
}

int main()
{
    vector<int> arr {5, 1, 4, 8, 2, 9};
    sort(arr);
    for(int i : arr)
        cout << i << " ";
}