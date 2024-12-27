#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

// A basic queue node for the custom queue (holds a Node pointer)
class QueueNode {
    public:
        Node* treeNode;
        QueueNode* next;
        QueueNode(Node* node) {
            treeNode = node;
            next = NULL;
        }
};

// A custom queue class to implement the queue functionality
class Queue {
    private:
        QueueNode* front;
        QueueNode* rear;
    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return front == NULL;
        }

        // Enqueue function to add a node at the rear
        void enqueue(Node* node) {
            QueueNode* temp = new QueueNode(node);
            if (rear == NULL) {
                front = rear = temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }

        // Dequeue function to remove a node from the front
        Node* dequeue() {
            if (isEmpty()) {
                return NULL;
            }
            QueueNode* temp = front;
            front = front->next;

            if (front == NULL) {
                rear = NULL;
            }

            Node* node = temp->treeNode;
            delete temp;
            return node;
        }

        // Get the front element without removing it
        Node* getFront() {
            if (isEmpty()) {
                return NULL;
            }
            return front->treeNode;
        }
};

// Function to build a tree from level-order input
Node* buildfromlevelorder(Node*& root) {
    Queue q1;
    int d;
    cout << "Enter data for root:" << endl;
    cin >> d;
    root = new Node(d);
    q1.enqueue(root);

    while (!q1.isEmpty()) {
        Node* temp = q1.dequeue();

        cout << "Enter Left Node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1) {
            temp->left = new Node(leftdata);
            q1.enqueue(temp->left);
        }

        cout << "Enter Right Node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1) {
            temp->right = new Node(rightdata);
            q1.enqueue(temp->right);
        }
    }
    return root;
}

// Function for level-order traversal
void level_order_traversal(Node* root) {
    Queue q1;
    q1.enqueue(root);
    q1.enqueue(NULL);

    while (!q1.isEmpty()) {
        Node* temp = q1.dequeue();
        if (temp == NULL) {
            cout << endl;
            if (!q1.isEmpty()) {
                q1.enqueue(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q1.enqueue(temp->left);
            }
            if (temp->right) {
                q1.enqueue(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    buildfromlevelorder(root);
    level_order_traversal(root);
}

