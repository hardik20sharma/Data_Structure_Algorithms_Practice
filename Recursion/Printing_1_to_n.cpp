/*
    WAP to print 1 to n using recursion
*/

#include<bits/stdc++.h>
using namespace std;

int dec_order(int n)
{
    if(n == 1)
        return 1;
    cout << n << " ";
    return dec_order(n-1);
}

void decreasing_order(int n)
{
    cout << n << " ";
    if(n != 1)
        decreasing_order(n-1);
}

void increasing_order(int n)
{
    if(n != 1)
        increasing_order(n-1);

    cout << n << " ";
}

int main()
{
    int n; cin >> n;
    increasing_order(n);    cout << "\n";
    decreasing_order(n);    cout << "\n";

    cout << dec_order(n) << "\n";
}
