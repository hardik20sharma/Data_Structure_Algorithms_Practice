#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> vec, int element)
{
    for(int i=0; i<vec.size(); i++)
        if(vec[i]==element)
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec{2, 3, 4, 10, 40};
    int res = linear_search(vec, 3);
    if(res==-1)
        cout << "Not Found\n";
    else
        cout << "Found at " << res << "\n";
}