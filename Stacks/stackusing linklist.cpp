#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node(int d){
			data=d;
			next=NULL;
		}
};
class stack{
	private:
		Node*top;
		public:
			stack(){
				top=NULL;
			}
			void push(int val){
				Node*newnode=new Node(val);
				newnode->next=top;
				top=newnode;
			}
			int pop(){
				if(top==NULL){
					cout<<"UNDERFLOW"<<endl;
					return -1;
				}
				Node*temp=top;
				int val=top->data;
				top=top->next;
				delete temp;
				return val;
			}
			int peek(){
				if(top!=NULL){
					return top->data;
				}
				return -1;
			}
			boolisempty(){
				if(top==NULL){
					return true;
				}
				return false;
			}
			void display(){
				Node*n=top;
				while(n!=NULL){
					cout<<n->data<<"->";
					n=n->next;
				}
				cout<<endl;
			}
};
int main(){
	stack s1;
	s1.push(20);
	s1.push(30);
	s1.display();
	cout<<s1.peek();
}
