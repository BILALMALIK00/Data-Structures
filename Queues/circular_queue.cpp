#include <iostream>
using namespace std;

class CircularQueue {
public:
    int front; 
    int rear;  
    int size;
    int *arr;

    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr; 
    }

    void enqueue(int val) {
        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (isempty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int val = arr[front];
        arr[front] = -1; 

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return val;
    }

    bool isempty() {
        return front == -1;
    }

    bool isfull() {
        return (rear + 1) % size == front;
    }

    void displayforward() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl; // Print the last element
    }
    void displaybackward(){
    	int i=rear;
    	while(i!=front){
    		cout<<arr[i]<<" ";
    		i=(i-1+size)%size;
		}
		cout<<arr[front];
	}
};

int main() {
    CircularQueue q1(5);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(9);
    q1.dequeue();
    //q1.displaybackward();
    q1.displayforward();
}

