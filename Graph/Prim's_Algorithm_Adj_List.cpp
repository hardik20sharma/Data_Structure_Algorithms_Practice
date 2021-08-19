#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    vector< list< pair<int, int> > > adj_List;

public:

    Graph(int vertices)
    {
        this->vertices = vertices;
        adj_List.resize(vertices, list< pair<int, int>> ());
    }

    void insert(int source, int destination, int weight)
    {
        adj_List[source].push_back( {destination, weight} );
        // adj_List[destination].push_back( {source, weight} );
    }

    void prims_algorithm()
    {
        vector<bool> visited (vertices, false);

        int initial_vertex = 0;
        visited[initial_vertex] = true;

        cout << "\n\nEdge : Weight\n";

        for(int no_of_edges_covered = 0; no_of_edges_covered < vertices - 1; no_of_edges_covered++)
        {
            int curr_vertex = initial_vertex, adj_Vertex_with_min_weight = 0, min_weight = INT_MAX;

            for( int i = 0; i < vertices; i++ )         // Source vertex
                if( visited[i] )                        // If visited already
                    for(pair<int, int> p : adj_List[i])
                        if(!visited[p.first])
                            if(min_weight > p.second)
                            {
                                min_weight = p.second;
                                curr_vertex = i;
                                adj_Vertex_with_min_weight = p.first;
                            }
            
            // Give the path from current vertex to adjacent vertex
            cout << curr_vertex << " - " << adj_Vertex_with_min_weight << " : " << min_weight << "\n";

            visited[adj_Vertex_with_min_weight] = true;
        }
    }
};

int main()
{
    Graph g(4);

    g.insert(0, 1, 10);
    g.insert(0, 2, 20);
    g.insert(1, 3, 5);
    g.insert(3, 2, 1);

    g.prims_algorithm();
}