#include<bits/stdc++.h>
using namespace std;

template<typename T>
void print_matrix(vector<vector<T>> matrix)
{
    for(int i = 0; i < matrix.size(); i++, cout << endl)
        for(int j = 0; j<matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
}

void sol(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++)
    {
        int i_temp = i, j_temp = 0;

        while(0 <= i_temp && j_temp < m)
            cout << matrix[i_temp--][j_temp++] << " ";
        
        cout << endl;
    }

    for(int j = 1; j < m; j++)
    {
        int i_temp = n-1, j_temp = j;

        while(0 <= i_temp && j_temp < m)
            cout << matrix[i_temp--][j_temp++] << " ";
        
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    print_matrix(matrix);
    sol(matrix);
}