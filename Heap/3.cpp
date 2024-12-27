#include<iostream>
using namespace std;

class PriorityQueue {
public:
    int* arr;        // Array to store elements in the heap
    int size;        // Current size of the priority queue
    int capacity;    // Capacity of the priority queue

    // Constructor to initialize the priority queue with a given capacity
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity + 1];  // 1-based index for the heap
    }

    // Insert an element into the priority queue
    void insert(int val) {
        if (size == capacity) {
            cout << "Priority Queue is full!" << endl;
            return;
        }
        
        // Insert the new element at the end of the heap
        size++;
        arr[size] = val;

        // Bubble up the newly added element to maintain the heap property
        int index = size;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] > arr[index]) {  // If parent is greater, swap
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Remove the element with the highest priority (smallest element)
    void deleteMin() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        
        // Replace the root with the last element in the heap
        arr[1] = arr[size];
        size--;

        // Bubble down to restore the heap property
        int i = 1;
        while (i <= size) {
            int smallest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            // Check if the left child is smaller
            if (left <= size && arr[left] < arr[smallest]) {
                smallest = left;
            }

            // Check if the right child is smaller
            if (right <= size && arr[right] < arr[smallest]) {
                smallest = right;
            }

            // If the smallest element is not the current element, swap
            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    // Peek the element with the highest priority (root of the heap)
    int peek() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return -1;  // Return a default value
        }
        return arr[1];
    }

    // Print the elements in the priority queue (heap)
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);
    
    // Insert elements into the priority queue
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(30);
    pq.insert(15);
    
    cout << "Priority Queue: ";
    pq.print();
    
    // Delete the element with the highest priority (smallest)
    pq.deleteMin();
    cout << "After deleting min (highest priority): ";
    pq.print();
    
    // Peek the element with the highest priority
    cout << "Peek (highest priority): " << pq.peek() << endl;
    
    return 0;
}

