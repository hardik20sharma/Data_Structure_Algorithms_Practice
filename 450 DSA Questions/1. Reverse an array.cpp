#include<bits/stdc++.h>
using namespace std;

void Print_Array(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    Print_Array(a, n);

    for(int i=0; i<n/2; i++)
        swap(a[i], a[n-i-1]);

    Print_Array(a, n);
}