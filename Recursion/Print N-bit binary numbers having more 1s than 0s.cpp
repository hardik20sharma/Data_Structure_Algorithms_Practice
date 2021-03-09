/*
    Given a positive integer N, print all N bit binary numbers having more 1’s than 0’s for any prefix of the number.

    Input:
    2
    2
    3
    Output:
    11 10
    111 110 101
*/
#include<bits/stdc++.h>
using namespace std;

void solve(int n, string output = "", int extra_ones = 0)
{
    if(n == 0)
    {
        cout << output << " "; return;
    }

    solve(n - 1, output + '1', extra_ones + 1);

    if(0 < extra_ones)
        solve(n - 1, output + '0', extra_ones - 1);
}

int main()
{
    int n = 3;
    solve(n);
}