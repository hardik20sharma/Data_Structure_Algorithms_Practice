#include<bits/stdc++.h>
using namespace std;

void Rotate_By_One (vector<int> &vec)
{
    int temp = vec[0];

    for(int i=0; i<vec.size() - 1; i++)
        vec[i] = vec[i+1];

    vec[vec.size()-1] = temp;
}

int main()
{
    vector<int> vec {1, 2, 3, 4, 5, 6};

    Rotate_By_One(vec);

    for(int i : vec)
        cout << i << " ";
}