#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec {1, -1, 3, -5, -6, 0, 2, 6};

    for(int i=0, j=0; i<vec.size(); i++)
        if(vec[i] < 0)
            if(i != j)
                swap(vec[i], vec[j++]);
    
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
}