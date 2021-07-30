#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    
    int vertices;
    vector < list <int> > adj_Lists;

public:

    Graph(int vertices)
    {
        this->vertices = vertices;
        adj_Lists.resize( vertices, list<int>() );
    }

    void add_Edge(int source, int destination)
    {
        adj_Lists[source].push_back(destination);
    }

    void bfs(int vertex)
    {
        vector <bool> visited (vertices, false);        // visiting no node right now

        visited[vertex] = true;                     // first vertex visited

        list<int> queue;            // creating a queue
        queue.push_back(vertex);    // and pushing current vertex in queue
        
        while(!queue.empty())       // Till queue is not empty
        {
            int curr_Vertex = queue.front();    // first element in the queue
            queue.pop_front();                  // pop the first element
            
            cout << curr_Vertex << " -> ";      // showing the current element

            for(int i : adj_Lists[curr_Vertex])     // traverse all vertices from current vertex
                if(!visited[i])                 // traverse all non-visited elements
                {
                    visited[i] = true;      // mark the vertex as visitied
                    queue.push_back(i);     // push it back in queue
                }
        }

        cout << "END" << endl;
    }
};

int main()
{
    Graph g(4);

    g.add_Edge(0, 1);
    g.add_Edge(0, 2);
    g.add_Edge(1, 2);
    g.add_Edge(2, 0);
    g.add_Edge(2, 3);
    g.add_Edge(3, 3);

    g.bfs(0);
    g.bfs(1);
    g.bfs(2);
    g.bfs(3);
}