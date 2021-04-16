#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec {0, 0, 0, 1, 2, 1, 0, 2, 1};

    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
    
    for(int i : vec)
        if(i == 0)
            cnt_0++;
        else if(i == 1)
            cnt_1++;
        else
            cnt_2++;
    
    int i = 0;
    while(cnt_0--)
        vec[i++] = 0;
    
    while(cnt_1--)
        vec[i++] = 1;
    
    while(cnt_2--)
        vec[i++] = 2;

    for(int i : vec)
        cout << i << " ";
}