#include<iostream>
using namespace std;
void heapify(int *arr,int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n&&arr[left]>arr[largest]){
		largest=left;
	}				
	if(right<n&&arr[right]>arr[largest]){
		largest=right;
	}	
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void buildheap(int *arr,int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
}
void heapsort(int *arr,int n){
	buildheap(arr,n);
	int index=n-1;
	while(index>=0){
		swap(arr[0],arr[index]);
		index--;
		heapify(arr,index,0);
			}
}
void display(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={10,9,8,7,6,5,4,3,2,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	heapsort(arr,size);
	display(arr,size);
}
