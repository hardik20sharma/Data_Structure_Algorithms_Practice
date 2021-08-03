#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{1,2,3,4,5,6,7,8,9,2,3,4,5,7};
    map<int, int> m;

    for(int i=0; i<a.size(); i++)
        m[a[i]]++;
    
    for(pair<int, int> x : m)
        if(x.second == 1)
        {
            cout << x.first;
            break;
        }
}