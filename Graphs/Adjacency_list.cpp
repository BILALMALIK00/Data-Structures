#include <iostream>
using namespace std;

class GraphList {
    int vertices;
    int **adjList; // Array of arrays
    int *size;     // Array to keep track of the size of each adjacency list
    int maxEdges;  // Maximum number of edges per vertex (fixed)

public:
    GraphList(int v, int maxE) {
        vertices = v;
        maxEdges = maxE;

        adjList = new int*[vertices];
        size = new int[vertices];

        for (int i = 0; i < vertices; i++) {
            adjList[i] = new int[maxEdges];
            size[i] = 0; // Initialize size of each adjacency list to 0
        }
    }

    void addEdge(int u, int v) {
        if (size[u] < maxEdges) {
            adjList[u][size[u]] = v; // Add edge u -> v
            size[u]++;
        }
        if (size[v] < maxEdges) {
            adjList[v][size[v]] = u; // Add edge v -> u (for undirected graph)
            size[v]++;
        }
    }

    void display() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < size[i]; j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~GraphList() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjList[i];
        }
        delete[] adjList;
        delete[] size;
    }
};

int main() {
    int vertices = 4;
    int maxEdges = 5; // Set a limit on the maximum edges per vertex
    GraphList graph(vertices, maxEdges);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3,3);
    graph.addEdge(1,3);

    graph.display();
    return 0;
}
