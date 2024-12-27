#include<iostream>
using namespace std;
//binary_Search
int searching_id(int *emp_id,int size,int rollnum_digit){
	int start=0;
	int end=size-1;
	int mid=(start+end)/2;
	while(start<=end){
		if((emp_id[mid]==rollnum_digit)){
			return mid;
		}else if(emp_id[mid]>rollnum_digit){
			end=mid-1;
		}else{
			start=mid+1;
		}
		mid=(start+end)/2;
	}
	return start;
}
int insert(int *&emp_id,int &n,int index,int target){
	int *newarr=new int[n+1];
	int cnt=0;
	for(int i=0;i<n+1;i++){
		if(i==index){
			newarr[index]=target;
		}else{
			newarr[i]=emp_id[cnt++];
		}
	}
	delete[]emp_id;
	emp_id=newarr;
	n++;
}
//int interpolation(int *arr,int s,int e,int target){
//	while(s<=e){
//		int position=s+(((target-arr[s])*(e-s)))/(arr[e]-arr[s]);
//		if(arr[position]==target){
//			return position;
//		}else if(arr[position]>target){
//			e=position-1;
//		}else{
//			s=position+1;
//		}
//	}
//	return -1;
//}
//int last_occurence(int *arr,int n,int target){
//	int s=0;
//	int e=n-1;
//	int ans=-1;
//	int mid=(s+e)/2;
//	while(s<=e){
//		if(arr[mid]==target){
//			ans=mid;
//		s=mid+1;
//		}
//		else if(arr[mid]>target){
//			e=mid-1;
//		}else{
//			s=mid+1;
//		}
//	mid=(s+e)/2;
//	}
//	return ans;
//}
//int first_occurence(int *arr,int n,int target){
//	int s=0;
//	int e=n-1;
//	int ans=-1;
//	int mid=(s+e)/2;
//	while(s<=e){
//		if(arr[mid]==target){
//			ans=mid;
//		e=mid-1;
//		}
//		else if(arr[mid]>target){
//			e=mid-1;
//		}else{
//			s=mid+1;
//		}
//	mid=(s+e)/2;
//	}
//	return ans;
//}
//int total_occurences(int *arr,int n,int target){
//	int first=first_occurence(arr,n,target);
//	int last=last_occurence(arr,n,target);
//	if(first==-1||last==-1){
//		return 0;
//	}
//	return last-first+1;
//}
void display(int *emp_id,int n){
	for(int i=0;i<n;i++){
		cout<<emp_id[i]<<" ";
	}
	cout<<endl;
}

int main(){
	///int arr[]={1,5,5,5,9};
	//int n=sizeof(arr)/sizeof(arr[0]);
//	int index=binary_search(arr,5,5);
//	if(index!=-1){
//		cout<<"Element Present at :"<<index;
//	}
//int index=interpolation(arr,0,5-1,5);
//		cout<<"Element Present at :"<<index;
//	int index=first_occurence(arr,n,5);
//	cout<<"Element Present at :"<<index<<endl;
//	int last=last_occurence(arr,n,5);
//		cout<<"Element Present at :"<<last<<endl;
//	int total=total_occurences(arr,n,5);
//	cout<<"Total occurence:"<<total<<endl;
	int n;
	cout<<"ENTER SIZE OF ARRAY:"<<endl;
	cin>>n;
	int *emp_id=new int[n];
	cout<<"ENTER EMP IDS:"<<endl;
	for(int i=0;i<n;i++){
		cin>>emp_id[i];
	}
	//sort(emp_id,n);
	int roll;
	cout<<"ENTER YOUR ROLL NUM:";
	cin>>roll;
		int last_two_digit=roll%100;
		int index=searching_id(emp_id,n,last_two_digit);
		if(index<n&&emp_id[index]==roll){
			cout<<"present"<<endl;
		}else{
			insert(emp_id,n,index,last_two_digit);
			display(emp_id,n);
		}
		
}
