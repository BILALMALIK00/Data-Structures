#include <iostream>
using namespace std;

// Maximum number of vertices
const int MAX = 100;

// Queue class implementation
class Queue {
private:
    int items[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = items[front];
        if (front >= rear) { // Reset the queue
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return item;
    }
};

// Node structure for adjacency list
class Node {
public:
    int vertex;
    Node* next;

    // Constructor to initialize the Node
    Node(int vertex) {
        this->vertex = vertex;
        this->next = NULL; // By default, next is null
    }
};

// Graph structure
class Graph {
public:
    Node* adjLists[MAX];  // Adjacency list for each vertex
    bool visited[MAX];     // Boolean array to track visited vertices
    int numVertices;       // Number of vertices in the graph

    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < vertices; i++) {
            adjLists[i] = NULL;  // Initialize each adjacency list as null
            visited[i] = false;      // Initialize all vertices as unvisited
        }
    }
    void addEdge(int src, int dest) {
        // Add dest to src's adjacency list
        Node* newNode = new Node(dest);  // Create new node with the destination vertex
        newNode->next = adjLists[src]; //head  // Link the current head of the list
    //head = newnode    adjLists[src] = newNode;         // Update the head to point to the new node

        // Add src to dest's adjacency list (for undirected graph)
        newNode = new Node(src);         // Create new node with the source vertex
        newNode->next = adjLists[dest];  // Link the current head of the list
        adjLists[dest] = newNode;        // Update the head to point to the new node
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

    void BFS(int startVertex) {
        Queue q;
        visited[startVertex] = true;
        q.enqueue(startVertex);

        while (!q.isEmpty()) {
           //front node
		    int currentVertex = q.dequeue();
            cout << currentVertex << " ";//oprint the front nodee

            Node* temp = adjLists[currentVertex];//finding neighours of node
            while (temp) {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    // Create a graph
    Graph graph(6);

    // Define edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 6);
    graph.addEdge(6, 4);
    graph.addEdge(2, 4);

    // Print the adjacency list for all vertices
    graph.printAdjList();

    // Perform BFS starting from vertex 1
    cout << "BFS Traversal : ";
    graph.BFS(1);
    cout << endl;

    return 0;
}

