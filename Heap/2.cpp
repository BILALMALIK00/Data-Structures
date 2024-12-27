#include<iostream>
using namespace std;

class minheap {
public:
    int* arr;
    int size;
    int capacity;

    minheap(int s) {
        arr = new int[s + 1]; 
        size = 0;
        capacity = s;
    }

    void insert(int val) {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }
    // Function to delete the root (min) and maintain heap property

    void deletion() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        // Replace the root with the last element
        arr[1] = arr[size];
        size--;

        // Downward heapify
        int i = 1;
        while (i <= size) {
            int smallest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= size && arr[left] < arr[smallest]) {
                smallest = left;
            }
            if (right <= size && arr[right] < arr[smallest]) {
                smallest = right;
            }
            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    // Utility to print heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Function to heapify a subtree rooted at index i
void heapify(int* arr, int size, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right <= size && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, size, smallest);
    }
}

// Build a heap from an unordered array
void buildheap(int* arr, int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }
}

// Perform heap sort
void heapsort(int* arr, int size) {
    // Build the heap
    buildheap(arr, size);

    // Sort the array
    int n = size;
    while (n > 1) {
        swap(arr[1], arr[n]);  // Swap root with last element
        n--;
        heapify(arr, n, 1);     // Restore heap property
    }
}

int main() {
    minheap h(10);
    h.insert(3);
    h.insert(1);
    h.insert(6);
    h.insert(5);
    h.insert(9);
    h.insert(8);
    
    cout << "Heap after insertions: ";
    h.print();

    h.deletion();  // Delete the root (min)
    cout << "Heap after deletion: ";
    h.print();

    // Heap sort example
    int arr[] = {0, 3, 1, 6, 5, 9, 8};  // 1-based index for heap
    int size = 6;
    heapsort(arr, size);
    
    cout << "Sorted array: ";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

