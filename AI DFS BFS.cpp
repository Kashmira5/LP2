#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int vertices;                     // Number of vertices
    vector<int> adj[10];              // Adjacency list
    bool visited[10];                 // Visited array

public:

    // Constructor
    Graph(int v) {
        vertices = v;

        // Initially mark all vertices as unvisited
        for(int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }

    // Function to add edge
    void addEdge(int u, int v) {

        // Because graph is undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Recursive DFS function
    void DFS(int start) {

        // Mark current node as visited
        visited[start] = true;

        // Print current vertex
        cout << start << " ";

        // Visit all adjacent vertices
        for(int i = 0; i < adj[start].size(); i++) {

            int next = adj[start][i];

            // Visit only if not visited
            if(!visited[next]) {
                DFS(next);
            }
        }
    }

    // BFS function
    void BFS(int start) {

        // Queue for BFS
        queue<int> q;

        // Separate visited array for BFS
        bool bfsVisited[10];

        // Initially all are unvisited
        for(int i = 0; i < vertices; i++) {
            bfsVisited[i] = false;
        }

        // Mark start node visited
        bfsVisited[start] = true;

        // Push start node into queue
        q.push(start);

        while(!q.empty()) {

            // Get front node
            int current = q.front();

            // Remove from queue
            q.pop();

            // Print current node
            cout << current << " ";

            // Visit neighbors
            for(int i = 0; i < adj[current].size(); i++) {

                int next = adj[current][i];

                // If not visited
                if(!bfsVisited[next]) {

                    bfsVisited[next] = true;

                    q.push(next);
                }
            }
        }
    }
};

int main() {

    // Create graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS Traversal: ";
    g.DFS(0);

    cout << endl;

    cout << "BFS Traversal: ";
    g.BFS(0);

    return 0;
}
