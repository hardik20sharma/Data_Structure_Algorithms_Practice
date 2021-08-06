#include<bits/stdc++.h>
using namespace std;

string s;

void dfs(vector<vector<bool>> matrix, int row, int col)
{
    matrix[row][col] = 0;   // Visitied

    if(0 <= row - 1 && matrix[row - 1][col])
    {
        s += "u";
        dfs(matrix, row - 1, col);
    }


    if(col + 1 < matrix[0].size() && matrix[row][col + 1])
    {
        s += "r";
        dfs(matrix, row, col + 1);
    }

    if(0 <= col - 1 && matrix[row][col - 1])
    {
        s += "l";
        dfs(matrix, row, col - 1);
    }

    if(row + 1 < matrix.size() && matrix[row + 1][col])
    {
        s += "d";
        dfs(matrix, row + 1, col);
    }

    s += "z";
}

int sol(vector<vector<bool>> &matrix)
{    
    set<string> se;

    for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[0].size(); j++)
            if(matrix[i][j])
            {
                s.clear();
                s += "x";
                dfs(matrix, i, j);
                se.insert(s);
            }

    return se.size();
}

int main()
{
    vector<vector<bool>> matrix = 
    {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0}
    };

    cout << sol(matrix);
}