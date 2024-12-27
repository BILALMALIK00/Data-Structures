#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
	int pivot=arr[s];
	int index=s+1;
	for(int i=s+1;i<=e;i++){
		if(arr[i]<=pivot){
			swap(arr[i],arr[index]);
			index++;
		}
	}
	swap(arr[index-1],arr[s]);
	return index-1;
}
void quick(int *arr,int s,int e){
	if(s>=e){
		return;
	}
	int p=partition(arr,s,e);
	quick(arr,s,p-1);
	quick(arr,p+1,e);
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
    int e = size - 1;
    cout << "Sorted: ";
    quick(arr, s, e);
    display(arr, size);
}
