//Find common elements in three sorted arrays

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{1,2,3,4,5,6}, b{4,5,6,7,8}, c{1,2,3,4,5,6,7,8,9};
    int i=0, j=0, k=0;

    while(i<a.size() && j<a.size() && k<a.size())
        if(a[i]==b[j] && b[j]==c[k])
        {
            cout << a[i] << " ";    i++;    j++;    k++;
        }
        else if(a[i] < b[j])
            i++;
        else if(b[j] < c[k])
            j++;
        else
            k++;
}