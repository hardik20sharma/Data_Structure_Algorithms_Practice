#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, n = sizeof(a) / sizeof(a[0]), k = 3;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int i : a)
    {
        max_heap.push(i);
        min_heap.push(i);

        if(max_heap.size() > k)
            max_heap.pop();
        if(min_heap.size() > k)
            min_heap.pop();
    }

    cout << max_heap.top() << " " << min_heap.top();
}