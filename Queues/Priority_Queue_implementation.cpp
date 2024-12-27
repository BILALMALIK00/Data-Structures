#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

class Priority_Queue {
private:
    Node* head;

public:
    Priority_Queue() {
        head = NULL;
    }

    void push(int data, int priority) {
        Node* temp = new Node(data, priority);
		// lowest priority comes first
        // If the queue is empty or the new node has higher priority than the head
        if (head == NULL || temp->priority < head->priority) {
            temp->next = head;
            head = temp;
        } else {
          
            Node* curr = head;
            while (curr->next != NULL && curr->next->priority <= temp->priority) {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void pop() {
        if (head == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (head == NULL) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << "Data: " << curr->data << ", Priority: " << curr->priority << endl;
            curr = curr->next;
        }
    }
};

int main() {
    Priority_Queue pq;
    pq.push(4, 1);
    pq.push(5, 2);
    pq.push(6, 0);
    pq.push(7, 2);

    cout << "Priority Queue:" << endl;
    pq.display();

    cout << "\nTop element: " << pq.top() << endl;

    cout << "\nPopping top element..." << endl;
    pq.pop();

    cout << "\nPriority Queue after popping:" << endl;
    pq.display();

    return 0;
}

