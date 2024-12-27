#include <iostream>
using namespace std;
void heapify(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
        arr[0] = -1;  
    }

    void insert(int val) {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

   void deletion() {
    if (size == 0) {
        cout << "Nothing To Delete" << endl;
        return;
    }
    arr[1] = arr[size];
    size--;  

    int i = 1;
    while (i <= size) {
        int left = 2 * i; 
        int right = 2 * i + 1;  
        int largest = i;  // Assume the largest element is the current node

        // Step 2: Find the largest among the current node, left child, and right child
        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }
		        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;  
        } else {
            break;  
        }
    }
}


    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Function to sort the heap in ascending order (using Max Heap)
void heapsort(int *arr, int n) {
    int i = n;
    while (i > 1) {
        swap(arr[i], arr[1]);
        i--;
        heapify(arr, i, 1);
    }
}

// Build heap function to create a max-heap from an array
void buildheap(int *arr, int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(89);
    h.insert(90);
    cout << "Heap after insertions: ";
    h.print();

    h.deletion();
    cout << "Heap after deletion: ";
    h.print();
      h.deletion();
       cout << "Heap after deletion: ";
         h.deletion();
    h.print();   cout << "Heap after deletion: ";
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // Perform heapify for each non-leaf node
    buildheap(arr, n);

    cout << "Heapified array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform heap sort to sort in ascending order (using max heap)
    heapsort(arr, n);

    cout << "Sorted array (ascending): ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

