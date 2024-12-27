#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node*left;
		Node*right;
		Node(int f){
			data=f;
			left=NULL;
			right=NULL;
		}
};
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node*insertintoBST(Node*root,int val){
	if(root==NULL){
		root=new Node(val);
		return root;
	}
	if(root->data>val){
		root->left=insertintoBST(root->left,val);
	}
	else{
		root->right=insertintoBST(root->right,val);
	}
	return root;
}

Node*input(Node*&root){
	int data;
	cout << "Enter data (-1 to stop): ";
	cin >>data;
	while(data!=-1){
		root=insertintoBST(root,data);
		cout << "Enter next data (-1 to stop): ";
		cin>>data;
	}
}
int solve(Node*root,int k,int &i){
	if(root==NULL){
		return -1;
	}
int left=	solve(root->left,k,i);
if(left!=-1){
	return left;
}
	i++;
	if(i==k){
		return root->data;
	}
	int right=solve(root->right,k,i);
	if(right!=-1){
		return right;
	}
}
int kSmallestelement(Node*root,int k){
	int i=0;
	int ans=solve(root,k,i);
}
int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to stop):" << endl;
    input(root);  
    cout << endl << "Inorder Traversal of the BST:" << endl;
    inorder(root);  
    int k=4;
 	int ksm=kSmallestelement(root,4);
 	cout<<endl;
 	cout<<k<< "Smallest Element In BST is :"<<ksm<<endl;
}
