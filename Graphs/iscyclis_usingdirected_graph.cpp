#include<iostream>
#include<vector>
using namespace std;

const int MAX_VERTICES = 100;

class Queue {
private:
    int queue[MAX_VERTICES];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(int value) {
        if (rear < MAX_VERTICES) {
            queue[rear++] = value;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            return queue[front++];
        }
        return -1;
    }

    int peek() {
        if (!isEmpty()) {
            return queue[front];
        }
        return -1;
    }
};

class Graph {
public:
    vector<int> adjLists[MAX_VERTICES];  // Adjacency list for the graph
    int visited[MAX_VERTICES];  // 0: unvisited, 1: visiting, 2: visited
    int numVertices;

    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < vertices; i++) {
            visited[i] = 0;  // All nodes are initially unvisited
        }
    }

    void addEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices) {
            cout << "Invalid edge!" << endl;
            return;
        }

        adjLists[src].push_back(dest);  // Directed edge from src to dest
    }

    bool isCyclicDFS(int current) {
        // Mark the current node as "visiting"
        visited[current] = 1;

        // Explore all neighbors using a regular for loop
        for (int i = 0; i < adjLists[current].size(); i++) {
            int neighbor = adjLists[current][i];
            if (visited[neighbor] == 1) {
                // If neighbor is in the "visiting" state, there's a cycle
                return true;
            }
            if (visited[neighbor] == 0) {
                // If the neighbor is unvisited, recursively visit it
                if (isCyclicDFS(neighbor)) {
                    return true;
                }
            }
        }

        // Mark the current node as "visited" after exploring all neighbors
        visited[current] = 2;
        return false;
    }

    bool isCyclicDFSWrapper() {
        // Run DFS from every unvisited vertex to handle disconnected components
        for (int i = 0; i < numVertices; i++) {
            if (visited[i] == 0) {  // Only start DFS if the node is unvisited
                if (isCyclicDFS(i)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicBFSWrapper() {
        // Run BFS from every unvisited vertex to handle disconnected components
        for (int i = 0; i < numVertices; i++) {
            if (visited[i] == 0) {  // Only start BFS if the node is unvisited
                if (isCyclicBFS(i)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicBFS(int start) {
        Queue q;
        int parent[MAX_VERTICES];

        // Initialize all nodes as unvisited and their parents as -1
        for (int i = 0; i < numVertices; i++) {
            parent[i] = -1;
            visited[i] = 0;  // Reset visited array for BFS
        }

        visited[start] = 1;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int current = q.dequeue();

            // Explore all neighbors using a regular for loop
            for (int i = 0; i < adjLists[current].size(); i++) {
                int neighbor = adjLists[current][i];

                // If the neighbor is visited and is not the parent, then a cycle is detected
                if (visited[neighbor] == 1 && neighbor != parent[current]) {
                    return true;
                }
                // If the neighbor is unvisited, visit it
                if (visited[neighbor] == 0) {
                    visited[neighbor] = 1;
                    parent[neighbor] = current;
                    q.enqueue(neighbor);
                }
            }
        }
        return false;
    }

    void resetVisited() {
        for (int i = 0; i < numVertices; i++) {
            visited[i] = 0;  // Reset visited array to unvisited
        }
    }

    void printAdjList() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j = 0; j < adjLists[i].size(); j++) {
                cout << adjLists[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4); 
    graph.addEdge(4, 0);  // This will form a cycle in the directed graph

    graph.printAdjList();

    graph.resetVisited();
    if (graph.isCyclicDFSWrapper()) {
        cout << "Cycle detected in the graph using DFS." << endl;
    } else {
        cout << "No cycle detected in the graph using DFS." << endl;
    }

    graph.resetVisited();
    if (graph.isCyclicBFSWrapper()) {
        cout << "Cycle detected in the graph using BFS." << endl;
    } else {
        cout << "No cycle detected in the graph using BFS." << endl;
    }

    return 0;
}

