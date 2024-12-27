#include<iostream>
using namespace std;
void heapify(int *arr,int n,int i){
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<=n&&arr[left]>arr[largest]){
		largest=left;
	}
	if(right<=n&&arr[right]>arr[largest]){
		largest=right;
	}
	if(i!=largest){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void buildheap(int*arr,int n){
	for(int i=n/2;i>0;i--){
		heapify(arr,n,i);
	}
}
	void heapsort(int *arr,int n){
		int i=n;
		while(i>1){
			swap(arr[i],arr[1]);
			i--;
			heapify(arr,i,1);
		}
	}
void display(int *arr,int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={9,8,7,6,5,4,6,7,8,9,6,35,3,2,4};
	int size=sizeof(arr)/sizeof(arr[0])-1;
	buildheap(arr,size);
	heapsort(arr,size);
	display(arr,size);
}
