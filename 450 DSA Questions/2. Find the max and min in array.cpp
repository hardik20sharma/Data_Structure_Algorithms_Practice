#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 1}, n = sizeof(a) / sizeof(a[0]),  min_ele = a[0], max_ele = a[0];
    
    for(int i=0; i<n; i++)
    {
        min_ele = min(min_ele, a[i]);
        max_ele = max(max_ele, a[i]);
    }

    cout << min_ele << " " << max_ele << "\n";
}