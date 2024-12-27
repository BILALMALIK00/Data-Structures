#include<iostream>
using namespace std;
class Node{
	public:
		Node*left;
		Node*right;
		int data;
		Node(int d){
			data=d;
			left=NULL;
			right=NULL;
		};
		
};
Node* insert(Node*root,int val){
	if(root==NULL){
		root=new Node(val);
	}
	if(root->data>val){
		root->left=insert(root->left,val);
	}
	else if(root->data<val){
		root->right=insert(root->right,val);
	}else{
		return root;
	}
	
}
Node*getmax(Node*root){
	if(root==NULL){
		return NULL;
	}
	if(root->right==NULL){
		return root;
	}
	return getmax(root->right);
}
Node* deletion(Node*root,int val){
	if(root==NULL){
		return NULL;
	}
	if(root->data>val){
		root->left=deletion(root->left,val);
	}else if(root->data<val){
		root->right=deletion(root->right,val);
	}else{
		if(root->left==NULL){
			Node*temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			Node*temp=root->left;
			delete root;
			return temp;
		}else{
		int maxi=getmax(root)->data;
			root->data=maxi;
			root->left=deletion(root->left,val);
		}
	}
	return root;
}
void inorder(Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* getpred(Node*root,int val){
	Node*pred=NULL;
	while(root!=NULL){
		if(root->data<val){
			pred=root;
			root=root->right;
		}else{
			root=root->left;
		}
	}
	return pred;
}
Node* getsucc(Node*root,int val){
	Node*succ=NULL;
	while(root!=NULL){
		if(root->data>val){
			succ=root;
			root=root->left;
		}else{
			root=root->right;
		}
	}
	return succ;
}
int main(){
	Node*root=NULL;
	root=insert(root,89);
	root=insert(root,890);
	root=insert(root,8);
	root=insert(root,9);
	root=insert(root,9);
	root=insert(root,90);
	root=insert(root,59);
	root=insert(root,29);
	root=insert(root,19);
	root=insert(root,79);

	inorder(root);
	cout<<endl;
	root=deletion(root,890);
	inorder(root);
	cout<<endl;
	Node* suu=getsucc(root,8);
	cout<<suu->data<<endl;
}
