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
    vector<int> adjLists[MAX_VERTICES];  
    bool visited[MAX_VERTICES];
    int numVertices;

    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }

    void addEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices) {
            cout << "Invalid edge!" << endl;
            return;
        }

        adjLists[src].push_back(dest);
       adjLists[dest].push_back(src);
    }

    bool isCyclicBFS(int start) {
        int parent[MAX_VERTICES];
        for (int i = 0; i < numVertices; i++) {
            parent[i] = -1;
        }

        Queue q;
        visited[start] = true;
        q.enqueue(start);
        
        while (!q.isEmpty()) {
            int front_node = q.dequeue();

            for (int i = 0; i < adjLists[front_node].size(); i++) {
                int neighbor = adjLists[front_node][i];
                if (visited[neighbor] && neighbor != parent[front_node]) {
                    return true;
                } else if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);
                    parent[neighbor] = front_node;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(int current, int parent) {
        visited[current] = true;

        for (int i = 0; i < adjLists[current].size(); i++) {
            int neighbor = adjLists[current][i];
            if (visited[neighbor] && neighbor != parent) {
                return true;
            } else if (!visited[neighbor]) {
                if (isCyclicDFS(neighbor, current)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicBFSWrapper() {
        return isCyclicBFS(0); 
    }

    bool isCyclicDFSWrapper() {
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                if (isCyclicDFS(i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    void resetVisited() {
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
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
    graph.addEdge(4, 0); 
    
    graph.printAdjList();

    graph.resetVisited();
    if (graph.isCyclicBFSWrapper()) {
        cout << "Cycle detected in the graph using BFS." << endl;
    } else {
        cout << "No cycle detected in the graph using BFS." << endl;
    }

    graph.resetVisited();
    if (graph.isCyclicDFSWrapper()) {
        cout << "Cycle detected in the graph using DFS." << endl;
    } else {
        cout << "No cycle detected in the graph using DFS." << endl;
    }

    return 0;
}

