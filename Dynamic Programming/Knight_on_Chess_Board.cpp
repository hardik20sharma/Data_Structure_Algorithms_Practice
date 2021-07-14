/*

Given a square chessboard of N x N size, the position of Knight and position of a target is given.We need to find out the minimum steps a Knight will take to reach the target position.

Examples:

In above diagram Knight takes 3 step to reach
from (4, 5) to (1, 1) (4, 5) -> (5, 3) -> (3, 2) -> (1, 1)  as shown in diagram

*/

#include<bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
    point(int x, int y) : x(x), y(y) { }
};

vector<point> dir { point(-2, -1), point(-1, -2), point(2, -1), point(1, -2), point(-2, 1), point(-1, 2), point(2, 1), point(1, 2), };

bool inside_board(point p, int n)
{
    return (p.x < 0 || p.y < 0 || n < p.x || n < p.y) ? false : true;
}

int min_steps_to_reach_destination(point start, point destination, int grid_size)
{
    vector<vector<int>> res (grid_size + 1, vector<int>(grid_size + 1, -1));
    res[start.x][start.y] = 0;

    queue<point> q;
    q.push(start);

    while(!q.empty())
    {
        point curr_point = q.front();
        q.pop();

        if(curr_point.x == destination.x && curr_point.y == destination.y)
            return res[destination.x][destination.y];

        for(int i = 0; i < 8; i++)
        {
            point next_point(curr_point.x + dir[i].x, curr_point.y + dir[i].y);

            if(inside_board(next_point, grid_size) && res[next_point.x][next_point.y] == -1)
            {
                res[next_point.x][next_point.y] = res[curr_point.x][curr_point.y] + 1;
                q.push(next_point);
            }
        }
    }

    return -1;
}

int main()
{
    int grid_size = 30;
    point start_pos(1, 1);
    point destination(30, 30);
    cout << min_steps_to_reach_destination(start_pos, destination, grid_size);
}