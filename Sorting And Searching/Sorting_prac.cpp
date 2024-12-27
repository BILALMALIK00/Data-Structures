#include<iostream>
using namespace std;
void selection_sort(int *arr,int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
			swap(arr[i],arr[min]);
		}
	}
}
void shell_sort(int *arr,int n){
	for(int gap=n/2;gap>0;gap/=2){
		for(int j=gap;j<n;j++){
			int temp=arr[j];
			int res=j;
			while(res>=gap&&arr[res-gap]>temp){
				arr[res]=arr[res-gap];
				res-=gap;
			}
			arr[res]=temp;
		}
	}
}

void display(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void insertion_sort(int *arr,int n){
	int i=1;
	while(i<n){
		int j=i-1;
		int temp=arr[i];
		while(j>=0&&arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		i++;
		arr[j+1]=temp;
	}
	
}
void merge(hash_entry **arr,int s,int e){
	int mid=(s+e)/2;
	int *arr1;int*arr2;
	int len1=mid-s+1;
	int len2=e-mid;
	arr1=new int[len1];
	arr2=new int[len2];
	int k=s;
	for(int i=0;i<len1;i++){
		arr1[i]=arr[k++];
	}
	k=mid+1;
	for(int i=0;i<len2;i++){
		arr2[i]=arr[k++];
	}
	int i=0;int j=0; k=s;
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
}
void merge_sort(int *arr,int s,int e){
	if(s>=e){
		return;
	}
	int mid=(s+e)/2;
	merge_sort(arr,s,mid);
	merge_sort(arr,mid+1,e);
	merge(arr,s,e);
}
int partition(int*arr,int s,int e){
	int mid=(s+e)/2;
	int pivot=arr[mid];
	int i=s;
	int j=e;
	while(i<=j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<=j){
			swap(arr[i++],arr[j--]);
		}
	}
	return i;
}
void quick_sort(int *arr,int s,int e){
	if(s>=e){
		return;
	}
	int p=partition(arr,s,e);
	quick_sort(arr,s,p-1);
	quick_sort(arr,p,e);
}


int main(){
	int arr[]={10,9,8,7,8,9,6,5,6,5,5,4,1,2,3,4,7,4,3};
	int size=sizeof(arr)/sizeof(arr[0]);
//	insertion_sort(arr,size);
//selection_sort(arr,size);
//merge_sort(arr,0,size-1);
//quick_sort(arr,0,size-1);
shell_sort(arr,size);
	display(arr,size);
}
