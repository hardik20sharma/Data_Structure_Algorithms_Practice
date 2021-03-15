#include<bits/stdc++.h>
using namespace std;

int jump_search(vector<int> vec, int element)
{
    int n = vec.size(), step = sqrt(n), prev=0;

    while(vec[min(step, n)-1] < element)
    {
        prev = step;
        step += sqrt(n);

        if(n <= prev)
            return -1;
    }

    while(vec[prev] < element)
        if(++prev == min(step, n))
            return -1;

    if(vec[prev] == element)
        return prev;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 40};
    int res = jump_search(vec, 40);
    (res==-1) ? cout << "Not Found\n" : cout << "Found at " << res << "\n";
}