#include<iostream>
using namespace std;
//void insertion_sort(int *arr,int n){
//	int i=1;
//	while(i<n){
//		int j=i-1;
//		int temp=arr[i];
//		while(j>=0&&arr[j]>temp){
//				arr[j+1]=arr[j];
//				j--;
//			}
//		arr[j+1]=temp;
//		i++;
//	}
//}
//void shell_sort(int *arr,int n){
//	for(int gap=n/2;gap>0;gap/=2){
//		for(int j=gap;j<n;j++){
//			int temp=arr[j];
//			int res=j;
//			while(res>=gap&&arr[res-gap]>temp){
//				arr[res]=arr[res-gap];
//				res-=gap;
//		}
//		arr[res]=temp;
//	}
//}
//}
//void selection_sort(int *arr,int n){
//	int min=0;
//	for(int i=0;i<n;i++){
//		int min=i;
//		for(int j=i+1;j<n;j++){
//			if(arr[j]<arr[min]){
//				min=j;
//			}
//		}
//		swap(arr[i],arr[min]);
//	}
//}
//void display(int *arr,int n){
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//}
void display(string pos[],int n){
	for(int i=0;i<n;i++){
		cout<<pos[i]<<" ";
	}
	cout<<endl;
}
int getpriority(string s){
	if(s=="CEO"){
		return 1;
	}else if(s=="CTO"){
		return 2;
	}else if(s=="CFO"){
		return 3;
	}else if(s=="VP"){
		return 4;
	}else if(s=="MGR"){
		return 5;
	}else if(s=="EMP"){
		return 6;
	}
	else {
		return -1;
	}
}
void sort(string position[],int n){
	int i=1;
	while(i<n){
		int j=i-1;
		string key=position[i];
		 int temp=getpriority(position[i]);
		while(j>=0&&getpriority(position[j])>temp){
			position[j+1]=position[j];
			j--;
		}
		position[j+1]=key;
		i++;
	}
}
int main(){
//	int arr[]={5,4,3,2,1};
//	int n=5;
	//insertion_sort(arr,5);
	//selection_sort(arr,5);
//	shell_sort(arr,5);
//	display(arr,5);
string pos[]={"EMP","CFO","MGR","EMP","VP","CTO","MGR","CEO"};
int size=sizeof(pos)/sizeof(pos[0]);
	sort(pos,size);
display(pos,size);
}
