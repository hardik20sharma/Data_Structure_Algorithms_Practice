/*

Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

Eulerian Cycle
An undirected graph has Eulerian cycle if following two conditions are true.
    a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
    b) All vertices have even degree.

Eulerian Path
An undirected graph has Eulerian Path if following two conditions are true.
    a) Same as condition (a) for Eulerian Cycle
    b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{

private:

    int vertices;
    vector<list<int>> adj_list;

    void dfs(int start, vector<bool> &visited)  // Depth First Search Function
    {
        visited[start] = true;          // Mark current vertex as visited

        for(int i : adj_list[start])    // Traversing other vertices from here
            if(visited[i] == false)
                dfs(i, visited);
    }

    bool is_connected()                         // Checks if all the vertices of graph are connected
    {
        vector<bool> visited(vertices, false);

        int i;

        // Ensures we have at least 1 non-zero vertex
        for(int i = 0; i < vertices; i++)
            if(adj_list[i].size() != 0)
                break;
        
        // This condition happens when we don't have any non-zero vertex
        if(i == vertices)
            return true;

        dfs(i, visited);

        // Check if all non-zero vertices are visited
        for(i = 0; i < vertices; i++)
            if(visited[i] == false && adj_list[i].size())
                return false;

        return true;
    }

    int is_eulerian()       // Checks if a graph is eulerian or not
    {
        if(is_connected() == false)     // If the graph is disconnected, return 0
            return 0;
        
        int count_vertices_with_odd_degree = 0;     // Finding the count of vertices with odd degree

        for(int i = 0; i < vertices; i++)
            if(adj_list[i].size() % 2 == 1)
                count_vertices_with_odd_degree++;

        if(count_vertices_with_odd_degree > 2)      // If there are more than 2 vertices with odd degree, then graph isn't eulerian 
            return 0;
        
        // If odd count is 2, then semi-eulerian.
        // If odd count is 0, then eulerian
        // Note that odd count can never be 1 for undirected graph

        return count_vertices_with_odd_degree ? 1 : 2;
    }
    
public:

    Graph(int vertices) {
        this->vertices = vertices;
        adj_list.resize(vertices, list<int>());
    }

    void add_edge(int start, int destination) {
        adj_list[start].push_back(destination);
        adj_list[destination].push_back(start);
    }

    void test()
    {
        int res = is_eulerian();

        if (res == 0)
            cout << "Graph is not Eulerian\n";
    
        else if (res == 1)
            cout << "Graph has a Euler path\n";
        
        else
            cout << "Graph has a Euler cycle\n";
    }
};

int main()
{
    Graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 1);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    g1.test();
  
    Graph g2(5);
    g2.add_edge(1, 0);
    g2.add_edge(0, 2);
    g2.add_edge(2, 1);
    g2.add_edge(0, 3);
    g2.add_edge(3, 4);
    g2.add_edge(4, 0);
    g2.test();
  
    Graph g3(5);
    g3.add_edge(1, 0);
    g3.add_edge(0, 2);
    g3.add_edge(2, 1);
    g3.add_edge(0, 3);
    g3.add_edge(3, 4);
    g3.add_edge(1, 3);
    g3.test();

    // Let us create a graph with 3 vertices connected in the form of cycle
    Graph g4(3);
    g4.add_edge(0, 1);
    g4.add_edge(1, 2);
    g4.add_edge(2, 0);
    g4.test();
  
    // Let us create a graph with all veritces with zero degree
    Graph g5(3);
    g5.test();
}