#include<iostream>
using namespace std;
void heapify(int *arr,int size,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size&&arr[left]>arr[largest]){
		largest=left;	
	}	
	if(right<size&&arr[right]>arr[largest]){
		largest=right;
	}if(largest!=i){
	swap(arr[i],arr[largest]);
	heapify(arr,size,largest);
}
}
void buildheap(int *Arr,int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(Arr,n,i);
	}
}

void heap_sort(int *arr,int n){
	int index=n-1;
	while(index>0){
		swap(arr[index],arr[0]);
		index--;
		heapify(arr,index,0);
	}
}
int getsmallest(int *arr,int k){
	return arr[k];
}
void display(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int arr[]={10,8,7,5,4,6,3,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	buildheap(arr,size);
	heap_sort(arr,size);
	int k;
	display(arr,size);
	cout<<endl;
	cout<<"Enter K:";
	cin>>k;
	int n=getsmallest(arr,k);
	cout<<k<< "  Smallest: "<<n<<endl;
}
