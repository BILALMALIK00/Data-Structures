#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
	int pivot=arr[s];
	int cnt=0;
	for(int i=s+1;i<=e;i++){
		if(arr[i]<=pivot){
			cnt++;
		}
	}
		int index=cnt+s;
swap(arr[s],arr[index]);
	int i=s;
	int j=e;
	while(i<index&&j>index){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<index&&j>index){
		swap(arr[i++],arr[j--]);
		
		}
	}
	return index;
}
void quick_sort(int *arr,int s,int e){
	if(s>=e){
		return;
	}
	int p=partition(arr,s,e);
	quick_sort(arr,s,p-1);
	quick_sort(arr,p+1,e);
}
void merge(int *arr,int s,int e){
	int mid=(s+e)/2;
	int len1=mid-s+1;
	int len2=e-mid;
	int *arr1=new int[len1];
	int *arr2=new int[len2];
	int k=s;
	int i=0;int j=0;
	for(int i=0;i<len1;i++){
		arr1[i]=arr[k++];
	}
	k=mid+1;
	for(int i=0;i<len2;i++){
		arr2[i]=arr[k++];
	}
	i=0,j=0,k=s;
	while(i<len1&&j<len2){
		if(arr1[i]<arr2[j]){
			arr[k++]=arr1[i++];
		}else{
			arr[k++]=arr2[j++];
		}
	}
	while(i<len1){
		arr[k++]=arr1[i++];
	}
	while(j<len2){
		arr[k++]=arr2[j++];
	}
	delete[]arr1;
	delete[]arr2;
}
void merge_sort(int*arr,int s,int e){
	int mid=(s+e)/2;
	if(s>=e){
		return;
	}
	merge_sort(arr,s,mid);
	merge_sort(arr,mid+1,e);
	merge(arr,s,e);
}

void display(int *arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
int main(){
	int arr[]={9,8,9,7,6,7,5,3,4,2,5,2,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	int s=0;
	int e=size-1;
	cout<<"Sorted:";
//	merge_sort(arr,s,e);
	quick_sort(arr,s,e);
	display(arr,size);
}
