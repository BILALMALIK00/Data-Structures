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
bool is_BST(Node*root,int min,int max){
	if(root==NULL){
		return true;
	}
	if(root->data<=min||root->data>=max){
		return false;
	}
	return is_BST(root->left,min,root->data)&&is_BST(root->right,root->data,max);
}
bool validate_BST(Node*root){
	is_BST(root,INT_MIN,INT_MAX);
}

int main(){
	Node*root=NULL;
	  cout << "Enter data to create BST (-1 to stop):" << endl;
	input(root);
	 cout << endl << "Inorder Traversal of the BST:" << endl;
    inorder(root);  
    cout<<endl;
    if(validate_BST(root)){
    	cout<<"BST IS VALID"<<endl;
	}else{
		cout<<"NOT VALID"<<endl;
	}
}
