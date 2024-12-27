#include <iostream>
using namespace std;

// Maximum number of vertices
const int MAX = 100;

// Node structure for adjacency list
class Node {
public:
    int vertex;
    Node* next;

    // Constructor to initialize a node with the given vertex
    Node(int v) {
        vertex = v;
        next = NULL;
    }
};

// Graph structure
class Graph {
public:
    Node* adjLists[MAX];  // Array of adjacency lists
    bool visited[MAX];     // Array to mark visited vertices
    int numVertices;       // Number of vertices in the graph

    // Constructor to initialize the graph with the number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < vertices; i++) {
            adjLists[i] = NULL;
            visited[i] = false;
        }
    }

    // Function to add an edge between src and dest
    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);
        newNode->next = adjLists[src];
        adjLists[src] = newNode;

        // Add src to dest's adjacency list (for undirected graph)
        newNode = new Node(src);
        newNode->next = adjLists[dest];
        adjLists[dest] = newNode;
    }

    // Recursive DFS function
    void DFS(int vertex) {
        // Mark the current node as visited
        visited[vertex] = true;
        cout << vertex << " ";  // Process the current node (print in this case)

        // Recur for all the adjacent vertices
        Node* temp = adjLists[vertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                DFS(adjVertex);  // Recursive call for unvisited adjacent vertex
            }
            temp = temp->next;
        }
    }

    // Function to print the adjacency list
    void printAdjList() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            Node* temp = adjLists[i];
            while (temp) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Define edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);

    // Print the adjacency list for all vertices
    graph.printAdjList();

    // Perform DFS starting from vertex 0
    cout << "DFS Traversal starting from vertex 0: ";
    graph.DFS(0);
    cout << endl;

    return 0;
}

