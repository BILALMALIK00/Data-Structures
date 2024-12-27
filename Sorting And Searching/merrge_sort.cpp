#include<iostream>
using namespace std;
void merge(int *arr,int start,int end){
	int mid=(start+end)/2;
	int len1=mid-start+1;
	int len2=end-mid;
	int*arr1;
	int *arr2;
	int i=0;
	int k=start;
	arr1=new int[len1];
	arr2=new int[len2];
	for(int i=0;i<len1;i++){
		arr1[i]=arr[k++];
	}
	k=mid+1;
	for(int i=0;i<len2;i++){
		arr2[i]=arr[k++];
	}
	i=0;
	int j=0;
	k=start;
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
void sort(int *arr,int start,int end){
	while(start>=end){
		return;
	}
	int mid=(start+end)/2;
	sort(arr,start,mid);
	sort(arr,mid+1,end);
	merge(arr,start,end);
}
int main(){
int arr[]={9,8,7,6,5,4,3,2,1};
int size=sizeof(arr)/sizeof(arr[0]);
int start=0;
int end=size-1;
sort(arr,start,end);
int i;
for(i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
}
