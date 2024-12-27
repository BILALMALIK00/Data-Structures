#include <iostream>
using namespace std;

int partition(int *arr, int s, int e) {
    int pivot = arr[e - 1];  // Use the second last element as pivot
    int p_index = s;         // Pointer for the next position for elements <= pivot

    // Loop through the array from s to e-1
    for (int i = s; i < e - 1; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[p_index]);
            p_index++;
        }
    }
    swap(arr[p_index], arr[e - 1]);  
    return p_index; 
}

void quick(int *arr, int s, int e) {
    if (s >=e) {
    	return;
    }
        int p = partition(arr, s, e);  
        quick(arr, s, p);             
        quick(arr, p + 1, e);          
    }

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1,0,1,2,3,10,9, 8, 9, 7, 6, 7, 5, 3, 4, 2, 5, 2, 1, 20, 0, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = size; 
    cout << "Sorted: ";
    quick(arr, s, e);
    display(arr, size);
}

