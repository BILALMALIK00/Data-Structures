#include <iostream>
#include <vector>
using namespace std;

const int Max = 1000;

class Queue {
public:
    int rear, front;
    int items[Max];

    Queue() {
        rear = front = -1;
        for (int i = 0; i < Max; i++) {
            items[i] = -1;
        }
    }

    void push(int val) {
        if (rear == Max - 1) {
            return;
        }
        if (front == -1) {
            rear++;
            items[rear] = val;
            front++;
        } else {
            rear++;
            items[rear] = val;
        }
    }

    int pop() {
        if (isempty()) {
            return -1;
        }
        int val = items[front];
        if (front >= rear) {
            rear = -1;
            front = -1;
        } else {
            front++;
        }
        return val;
    }

    bool isempty() {
        return front == -1;
    }
};

class Graph {
public:
    vector<int> adjList[Max]; // Using vector to represent adjacency list
    int numofvertices;
    bool visited[Max];

    Graph(int v) {
        numofvertices = v;
        for (int i = 0; i < numofvertices; i++) {
            visited[i] = false;
        }
    }

    void add_edge(int src, int dest) {
        adjList[src].push_back(dest);
        // For undirected graph
        adjList[dest].push_back(src);
    }

    void Bfs(int vertex) {
        Queue q1;
        visited[vertex] = true;
        q1.push(vertex);

        while (!q1.isempty()) {
            int front_node = q1.pop();
            cout << front_node << " ";
            // Traverse the adjacency list for the current node
            for (int i = 0; i < adjList[front_node].size(); i++) {
                int adjvertex = adjList[front_node][i];
                if (!visited[adjvertex]) {
                    visited[adjvertex] = true;
                    q1.push(adjvertex);
                }
            }
        }
    }

    void printAdjlist() {
        for (int i = 0; i < numofvertices; i++) {
            cout << "Adjacency List for " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(1, 3);
    g1.add_edge(3, 4);
    g1.add_edge(4, 2);
    g1.add_edge(1, 2);

    g1.printAdjlist();
    cout << endl;
    g1.Bfs(0); // Perform BFS starting from vertex 0
}

