#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		public:
			Node(int d){
				data=d;
				next=NULL;
			}
};
Node* reverse(Node*head){
	if(head==NULL){
		return NULL;
	}
	Node*curr=head;
	Node*prev=NULL;
	Node*forward=NULL;
	while(curr){
		forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	return prev;
}
Node*getmiddle(Node*head){
	Node*fast=head->next;
	Node*slow=head;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;
	}
	return slow;
}
void insertattail(Node*&head,Node*&tail,int val){
	Node*temp=new Node(val);
	if(head==NULL){
		head=temp;
		tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
}
void display(Node*head){
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ->";
		temp=temp->next;
	}
}
int main(){
	Node*head=NULL;
	Node*tail=NULL;
	insertattail(head,tail,2);
		insertattail(head,tail,8);
	insertattail(head,tail,29);
	insertattail(head,tail,8);

//	display(head);
//Node*rev=reverse(head);
//cout<<endl;
//display(rev);
cout<<endl;
	Node*mid=getmiddle(head);
	cout<<mid->data<<endl;
}
