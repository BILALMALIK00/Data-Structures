#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node*left;
	Node*right;
	public:
		Node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
int Ksmallest(Node*root,int &i,int k){
	if(root==NULL){
		return -1;
	}
	int left=Ksmallest(root->left,i,k);
	if(left!=-1){
		return left;
	}
	i++;
	if(i==k){
		return root->data;
	}
	return Ksmallest(root->right,i,k);
	
}

Node*insert(Node*root,int data){
	if(root==NULL){
		root=new Node(data);
		return root;
	}
	if(root->data<data){
		root->right=insert(root->right,data);
	}
	if(root->data>data){
		root->left=insert(root->left,data);
	}
	return root;
}
void input(Node*&root){
	int data;
	cout<<"Enter data:";
	cin>>data;
	while(data!=-1){
		root=insert(root,data);
		cout<<"Enter Data(-1 to stop):";
		cin>>data;
	}
}
void inorder(Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node*predecessor(Node*root,int data){
	if(root==NULL){
		return NULL;
	}
	Node*pred= NULL;
	while(root!=NULL){
		if(root->data<data){
			pred=root;
			root=root->right;
		}else{
		root=root->left;
	}
	}
	return pred;
}
int main(){
	Node*root=NULL;
	input(root);
	cout<<"Inorder Traversal: ";
	inorder(root);
	cout<<endl;
	cout<<"K smallest:"<<endl;
	int i=0;
	int ans=Ksmallest(root,i,3);
	cout<<ans<<endl;
}
