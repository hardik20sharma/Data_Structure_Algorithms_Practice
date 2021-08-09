#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:

    int vertices;                       // Store the total number of vertices
    vector< list<int> > adj_Lists;      // Array of adjacent list

    
    void dfs_Util(int vertex, vector<bool> &visited) // DFS Utility Function
    {
        visited[vertex] = true;                     // We have visited the vertex, mark it true
        list <int> adj_List_Curr_Vertex = adj_Lists[vertex]; // Adjacency list for curr vertex

        cout << vertex << " ";

        for(int i : adj_List_Curr_Vertex) // Traverse vertices stored in adjacency list of curr vertex
            if(!visited[i])     // Only traversal when not visited
                dfs_Util(i, visited);
    }

public:

    Graph(int vertices)     // Constructor
    {
        this->vertices = vertices;                  // Number of vertices
        adj_Lists.resize( vertices, list<int>() );  // Initializes adjacent list for each vertices
    }

    void add_Edge(int source, int destination)  // Adding edges -- Function
    {
        adj_Lists[source].push_back(destination);   // Adding edge, source to destination
    }

    void dfs(int vertex)    // DFS Function
    {
        vector<bool> visited(vertices, false);
        dfs_Util(vertex, visited);
        cout << endl;
    }
};

int main()
{
    Graph g(4);
    g.add_Edge(0, 1);
    g.add_Edge(0, 2);
    g.add_Edge(1, 2);
    g.add_Edge(2, 3);

    g.dfs(1);
    g.dfs(3);
    g.dfs(0);
}