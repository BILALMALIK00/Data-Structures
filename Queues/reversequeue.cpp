#include <iostream>
#include <stack>
using namespace std;

class queue {
public:
    int front; // pop --> front
    int rear;  // push --> rear
    int size;
    int *arr;

    queue(int s) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int val) {
        if (!isfull()) {
            arr[rear] = val;
            rear++;
        } else {
            cout << "Queue is full" << endl;
        }
    }

    int dequeue() {
        int val;
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            val = arr[front];
            arr[front] = -1;
            front++;
        }
        if (front == rear) {
            rear = 0;
            front = 0;
        }
        return val;
    }

    bool isempty() {
        return front == rear;
    }

    bool isfull() {
        return rear == size;
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getfront() {
        if (!isempty()) {
            return arr[front];
        }
        return -1;
    }
};

// Function to reverse the first k elements of the queue
void reversefirstk(queue &q1, int k) {
    if (k > q1.rear) { // Boundary check to ensure k is valid
        cout << "Invalid value of k" << endl;
        return;
    }
    stack<int> s1;
    
    // Step 1: Push first k elements onto stack
    for (int i = 0; i < k; i++) {
        int val = q1.getfront();
        q1.dequeue();
        s1.push(val);
    }

    // Step 2: Enqueue the elements from the stack (reversed order)
    while (!s1.empty()) {
        int val = s1.top();
        s1.pop();
        q1.enqueue(val);
    }

    int t = q1.rear - k; // Remaining elements after reversing first k
    while (t--) {
        int val = q1.getfront();
        q1.dequeue();
        q1.enqueue(val);
    }
}

// Function to reverse the entire queue
void reverse(queue &q1) {
    stack<int> s1;
    while (!q1.isempty()) {
        int val = q1.getfront();
        q1.dequeue();
        s1.push(val);
    }
    while (!s1.empty()) {
        int val = s1.top();
        s1.pop();
        q1.enqueue(val);
    }
}

int main() {
    queue q1(5);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(9);
    q1.enqueue(2);
    q1.enqueue(7);

    cout << "Original queue: ";
    q1.display();

    // Reverse the entire queue
    reverse(q1);
    cout << "Queue after reversing entire queue: ";
    q1.display();

    // Reverse the first k elements (e.g., k = 3)
    reversefirstk(q1, 3);
    cout << "Queue after reversing first 3 elements: ";
    q1.display();

    return 0;
}

