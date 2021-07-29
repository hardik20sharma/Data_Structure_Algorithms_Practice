#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices;
    vector< vector<int> > adj_Matrix;

public:

    Graph(vector< vector<int> > matrix)
    {
        vertices = matrix.size();
        adj_Matrix = matrix;
    }

    void print_Matrix()
    {
        cout << "\n\n";
        for(int i=0; i<vertices; i++, cout << "\n")
            for(int j=0; j<vertices; j++)
                if(adj_Matrix[i][j])
                    cout << "From " << i << " to " << j << ", Cost: " << adj_Matrix[i][j] << "\n";
    }
};

int main()
{
    vector< vector<int> > matrix = {

        {  0,  9,  75,   0,  0 },
        {  9,  0,  95,  19, 42 },
        { 75, 95,   0,  51, 66 },
        {  0, 19,  51,   0, 31 },
        {  0, 42,  66,  31,  0 }
    };

    Graph g(matrix);
    g.print_Matrix();
}