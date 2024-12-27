#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
int pivot=arr[s];
int cnt=0;
for(int i=s+1;i<=e;i++){
	if(arr[i]>=pivot){
		cnt++;
	}
}
	int index=cnt+s;
	swap(arr[s],arr[index]);
	int i=s;
	int j=e;
	while(i<index&&j>index){
		while(arr[i]>pivot){
			i++;
		}
		while(arr[j]<pivot){
			j--;
		}
		if(i<index&&j>index){
		swap(arr[i++],arr[j--]);
	}
}
	return index;
}
void quicksort(int *arr,int s,int e){
	if(s>=e){
		return;
	}
	int p=partition(arr,s,e);
	quicksort(arr,s,p-1);
	quicksort(arr,p+1,e);
}
void display(int *arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[]={10,6,7,4,7,4,6,5,4,3,2,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	display(arr,size);
	int s=0;
	int e=size-1;
	quicksort(arr,s,e);
	display(arr,size);
}
