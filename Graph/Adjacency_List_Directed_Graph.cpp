#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices;   // Stores the number of vertices

    // Vector stores source, pair stores destinations and cost
    
    vector< list< pair<int, int> > > adj_List;

public:

    Graph(int vertices)
    {
        this->vertices = vertices;

        // Create a vector of size vertices
        adj_List.resize( vertices, list< pair<int, int> >() );
    }

    void add_Edge(int source, int destination, int cost)
    {
        adj_List[source].push_back( {destination, cost} );  // Add edge along with cost
    }

    void print_Graph()      // Printing graph
    {
        for(int source = 0; source < vertices; source++)    // Iterating through each vertex
            for(auto destination : adj_List[source])        // Printing each destination and cost
                cout << "From " << source << " to " << destination.first << ", Cost: " << destination.second << "\n";
    }
};

int main()
{
    Graph g(3);     // Graph of 3 vertices

    g.add_Edge(0, 1, 50);       // Source -> Destination with cost
    g.add_Edge(1, 2, 10);
    g.add_Edge(2, 1, 100);
    g.add_Edge(2, 0, 0);

    g.print_Graph();
}
