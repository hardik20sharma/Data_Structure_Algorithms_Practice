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
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
                                // R, D, L, U
    int possible_direction_i[4] = {0, 1, 0, -1};
    int possible_direction_j[4] = {1, 0, -1, 0};

    int i = 0, j = 0, direction = 0;

    for(int element_count = 0; element_count < n * m; element_count++)
    {
        cout << matrix[i][j];
        if(element_count != n*m-1)
            cout << " -> ";

        visited[i][j] = true;

        int i_next = i + possible_direction_i[direction];
        int j_next = j + possible_direction_j[direction];

        if(0 <= i_next && i_next < n && 0 <= j_next && j_next < m && visited[i_next][j_next] == false)
        {
            i = i_next;
            j = j_next;
        }
        else
        {
            direction = (direction + 1) % 4;
            i += possible_direction_i[direction];
            j += possible_direction_j[direction];
        }
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
