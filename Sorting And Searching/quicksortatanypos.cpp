#include <iostream>
using namespace std;
int partition(int *arr, int s, int e) {
    int pivot = arr[s + 1]; //2nd element
	int cnt=0;
	for(int i=s+2;i<=e;i++){
		if(arr[i]<=pivot){
			cnt++;
		}
	}
	int index=cnt+s;
	swap(arr[index],pivot);
	int i=s;
	int j=e;
	while(i<index&&j>index){
		while(arr[i]<index){
			i++;
		}
		while(arr[j]>index){
			j--;
		}
		if(i<index&&j>index){
			swap(arr[i++],arr[j--]);
		}
	}
	return index;
    
}

// QuickSort function
void quick(int *arr, int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e);  // Partition the array
        quick(arr, s, p-1);               // Recursively sort the left part
        quick(arr, p + 1, e);           // Recursively sort the right part
    }
}


// Function to display the sorted array
void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 0, 1, 2, 3, 10, 9, 8, 9, 7, 6, 7, 5, 3, 4, 2, 5, 2, 1, 20, 0, 9};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int s = 0;
    int e = size - 1;

    cout << "Original array: ";
    display(arr, size); 
    quick(arr, s, e); 
    cout << "Sorted: ";
    display(arr, size); 

    return 0;
}

