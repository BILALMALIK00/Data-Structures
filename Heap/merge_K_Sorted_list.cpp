#include<iostream>
using namespace std;

// Define a node structure for the linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// A simple min-heap class to handle the heap operations
class MinHeap {
private:
    ListNode** heap;  // Pointer to an array of ListNode pointers
    int size;         // Current size of the heap
    int capacity;     // Maximum capacity of the heap
    
    // Function to swap two nodes in the heap
    void swap(int i, int j) {
        ListNode* temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    
    // Function to heapify the heap after insertion
    void heapifyUp(int idx) {
        while (idx > 1 && heap[idx]->val < heap[idx / 2]->val) {
            swap(idx, idx / 2);
            idx = idx / 2;
        }
    }
    
    // Function to heapify the heap after extraction
    void heapifyDown(int idx) {
        int smallest = idx;
        int left = 2 * idx;
        int right = 2 * idx;
        
        if (left <= size && heap[left]->val < heap[smallest]->val) {
            smallest = left;
        }
        
        if (right <= size && heap[right]->val < heap[smallest]->val) {
            smallest = right;
        }
        
        if (smallest != idx) {
            swap(idx, smallest);
            heapifyDown(smallest);
        }
    }
    
public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new ListNode*[cap + 1];  // 1-based indexing
    }

    // Insert a new node into the heap
    void insert(ListNode* node) {
        if (size < capacity) {
            heap[++size] = node;
            heapifyUp(size);
        }
    }

    // Extract the minimum element (the root)
    ListNode* extractMin() {
        if (size == 0) {
            return NULL;
        }
        
        ListNode* minNode = heap[1];
        heap[1] = heap[size--];
        heapifyDown(1);
        return minNode;
    }

    // Check if the heap is empty
    bool isEmpty() {
        return size == 0;
    }
};

// Function to merge K sorted linked lists using a min-heap
ListNode* mergeKLists(ListNode* lists[], int k) {
    if (k == 0) return NULL;
    
    // Create a min-heap with K elements (one from each linked list)
    MinHeap heap(k);
    
    // Insert the head node of each list into the heap
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            heap.insert(lists[i]);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    // Extract the minimum node from the heap and add it to the merged list
    while (!heap.isEmpty()) {
        ListNode* minNode = heap.extractMin();
        current->next = minNode;
        current = current->next;
        
        // If the extracted node has a next node, insert it into the heap
        if (minNode->next != NULL) {
            heap.insert(minNode->next);
        }
    }
    
    return dummy->next;
}

// Helper function to insert a new node at the end of the linked list
ListNode* insertNode(ListNode* head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int k = 3;
    ListNode* lists[k];

    // Create and insert elements into each linked list
    lists[0] = NULL;
    lists[0] = insertNode(lists[0], 1);
    lists[0] = insertNode(lists[0], 4);
    lists[0] = insertNode(lists[0], 5);

    lists[1] = NULL;
    lists[1] = insertNode(lists[1], 1);
    lists[1] = insertNode(lists[1], 3);
    lists[1] = insertNode(lists[1], 4);

    lists[2] = NULL;
    lists[2] = insertNode(lists[2], 2);
    lists[2] = insertNode(lists[2], 6);

    // Merge all K sorted linked lists using a min-heap
    ListNode* result = mergeKLists(lists, k);

    // Print the merged linked list
    cout << "Merged Sorted Linked List: ";
    printList(result);

    return 0;
}

