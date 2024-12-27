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
	cout<<"Null"<<endl;
	cout<<endl;
}
Node* getmiddle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* fast = head->next;
    Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next;
		fast=fast->next; 
        slow = slow->next;       
    }
    return slow;
}

Node*merge(Node*left,Node*right){
	if(left==NULL){
		return right;
	}
	if(right==NULL){
		return left;
	}
	Node*dummy=new Node(-1);
	Node*temp=dummy;
	while(left!=NULL&&right!=NULL){
		if(left->data<right->data){
			temp->next=left;
			temp=left;
			left=left->next;
		}else{
			temp->next=right;
			temp=right;
			right=right->next;
		}
	}
	while(left!=NULL){
			temp->next=left;
			temp=left;
			left=left->next;
	}
	while(right!=NULL){
			temp->next=right;
			temp=right;
			right=right->next;
	}
	return dummy->next;
}
Node*mergesort(Node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node*mid=getmiddle(head);
	Node*left=head;
	Node*right=mid->next;
	mid->next=NULL;
	left=mergesort(left);
	right=mergesort(right);
	
	Node*newhead=merge(left,right);
	return newhead;
	
}
int main(){
	Node*head=NULL;
	Node*tail=NULL;
	insertattail(head,tail,6);
	insertattail(head,tail,8);
	insertattail(head,tail,3);
	insertattail(head,tail,2);
	insertattail(head,tail,1);
	insertattail(head,tail,4);
	insertattail(head,tail,6);
	insertattail(head,tail,8);
	cout<<"Original:";
	display(head);
	cout<<"Sorted list:";
	Node*newhead=mergesort(head);
	display(newhead);

}
