#include<iostream>
using namespace std;
class twostack{
	public:
		int size;
		int *arr;
		int top1;
		int top2;
		twostack(int s){
			size=s;
			arr=new int[size];
			top1=-1;
			top2=s;
		}
		void push1(int x){
			if(top2-top1>1){
				top1++;
				arr[top1]=x;
			}else{
				cout<<"stack1 full"<<endl;
			}
		}
		void push2(int x){
			if(top2-top1>1){
				top2++;
				arr[top2]=x;
			}else{
				cout<<"stack2 full"<<endl;
			}
		}
		int pop1(){
			if(top1!=-1){
				int t=arr[top1];
				top1--;
				return t;
			}else{
				cout<<"stack empty"<<endl;
			}
		}
		int pop2(){
			if(top2!=size){
				int t=arr[top2];
				top2--;
			}
			else{
				cout<<"stack2 empty"<<endl;
			}
		}
		void dislay1(){
			while(top1!=-1){
				cout<<arr[top1]<<" ";
				top1--;
			}
		}
			void dislay2(){
			while(top2!=size){
				cout<<arr[top2]<<" ";
				top2--;
			}
		}
};
int main(){
	twostack s1(5);
	s1.push1(6);
	s1.push1(5);
	s1.push2(8);
	s1.push2(9);
	s1.dislay1();
	s1.dislay2();
}
