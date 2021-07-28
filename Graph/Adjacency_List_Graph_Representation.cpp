#include<bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adjacency_list[], int u, int v)
{
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
}

void print_Graph(vector<int> adjacency_list[], int V)
{
    for(int v = 0; v < V; v++)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        
        for (auto x : adjacency_list[v])
           cout << "-> " << x;
        
        cout << endl;
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    add_Edge(adj, 0, 1);
    add_Edge(adj, 0, 4);
    add_Edge(adj, 1, 2);
    add_Edge(adj, 1, 3);
    add_Edge(adj, 1, 4);
    add_Edge(adj, 2, 3);
    add_Edge(adj, 3, 4);
    print_Graph(adj, V);
    return 0;
}