#include<iostream>
using namespace std;
class queue{
	public:
		int front;//pop--->front
		int rear;//push-->rear 
		int size;
		int *arr;
		queue(int s){
			size=s;
			arr=new int[size];
			front=0;
			rear=0;
		}
		void enqueue(int val){
			if(!isfull()){
				arr[rear]=val;
				rear++;
			}else{
				cout<<"queue is full"<<endl;
			}
		}
	int  dequeue(){
		int val;
			if(front==rear){
				cout<<"Empty"<<endl;
				return -1;
			}else{
				val=arr[front];
				arr[front]=-1;
				front++;
			}
			if(front==rear){
				rear=0;
				front=0;
			}
			return val;
		}
		bool isempty(){
			if(front==rear){
				return true;
			}
			return false;
		}
		bool isfull(){
			if(rear==size-1){
				return true;
			}
			return false;
		}
		void display(){
		for(int i=front;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
			cout<<endl;
		}
};
int main(){
	queue q1(5);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(9);
	q1.dequeue();
	q1.display();
	if(q1.isempty()){
		cout<<"empty"<<endl;
	}else{
		cout<<"Not empty"<<endl;
	}
}
