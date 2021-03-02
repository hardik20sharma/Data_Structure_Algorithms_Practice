#include<bits/stdc++.h>
using namespace std;

long long toh(int n, int from, int to, int aux)
{
    if(n == 1)
    {
        cout << "move disk " << n << " from rod " << from << " to rod " << to << "\n";
        return 1;
    }

    int res = toh(n-1, from, aux, to);

    cout << "move disk " << n << " from rod " << from << " to rod " << to << "\n";

    res += toh(n-1, aux, to, from) + 1;

    return res;
}

int main()
{
    cout << toh(n, 1, 3, 2);
}
