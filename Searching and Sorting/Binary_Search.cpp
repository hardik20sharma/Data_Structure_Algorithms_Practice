#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> vec, int low, int high, int element)
{
    if(high < low)
        return -1;
    
    int mid = low + (high - low) / 2;

    if(vec[mid]==element)
        return mid;
    else if(vec[mid] > element)
        return binary_search(vec, low, mid-1, element);
    else
        return binary_search(vec, mid+1, high, element);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec{2, 3, 4, 10, 40};
    int res = binary_search(vec, 0, vec.size()-1, 2);
    if(res==-1)
        cout << "Not Found\n";
    else
        cout << "Found at position: " << res << "\n";
}