//      Delete Middle Element of a Stack Using Recursion.

#include<bits/stdc++.h>
using namespace std;

void stack_delete(stack<int> &s, int pos)
{    
    int temp = s.top();
    s.pop();

    if(pos)
    {
        stack_delete(s, pos - 1);
        s.push(temp);
    }
}

void print(stack<int> s)
{
    for( ; !s.empty(); s.pop())
        cout << s.top() << " ";
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(6);
    s.push(9);
    s.push(5);
    s.push(4);

    print(s);
    stack_delete(s, s.size() / 2); cout << "\n";
    print(s);
}