#include<iostream>
using namespace std;
class Node{
	public:
		Node*left;
		Node*right;
		int data;
		int height;
		Node(int va){
			data=va;
			height=1;
			left=NULL;
			right=NULL;
		}
};
Node*getmax(Node*root){
		if(root==NULL||root->right==NULL){
			return root;
		}
	return getmax(root->right);
}
	int getheight(Node*root){
	if(root==NULL){
		return 0;
	}
return root->height;
	}
	int balancefactor(Node*root){
		if(root==NULL){
			return 0;
		}
		return getheight(root->left)-getheight(root->right);
	}
	Node*LLrotation(Node*root){
		Node*rootl=root->left;
		root->left=rootl->right;
		rootl->right=root;
		root->height=1+max(getheight(root->left),getheight(root->right));
		rootl->height=1+max(getheight(rootl->left),getheight(rootl->right));
		return rootl;
			
			}
			
			
			Node*RRrotation(Node*root){
				Node*rootr=root->right;
				root->right=rootr->left;
				rootr->left=root;
				root->height=1+max(getheight(root->left),getheight(root->right));
				rootr->height=1+max(getheight(rootr->left),getheight(rootr->right));
				return rootr;

			}
			
			Node*LRrotation(Node*root){
				root->left=RRrotation(root->left);
				return LLrotation(root);
			}
			
			Node*RLrotation(Node*root){
				root->right=LLrotation(root->right);
				return RRrotation(root);
			}

	Node* insert(Node*root,int val){
		if(root==NULL){
			root=new Node(val);
			return root;
		}
		if(root->data>val){
			root->left=insert(root->left,val);
		}else if(root->data<val){
			root->right=insert(root->right,val);
		}else{
			return root;
		}
		int factor=balancefactor(root);
		root->height=1+max(getheight(root->left),getheight(root->right));
		if(factor>1&&root->left->data>val){
			return LLrotation(root);
		}
			if(factor>1&&root->left->data<val){
			return LRrotation(root);
		}
			if(factor<-1&&root->right->data<val){
			return RRrotation(root);
		}
			if(factor<-1&&root->right->data>val){
			return RLrotation(root);
		}
		return root;
	}
	
	Node*Deletion(Node*root,int val){
		if(root==NULL){
			return NULL;
		}
		if(root->data<val){
			root->right=Deletion(root->right,val);
		}else if(root->data>val){
			root->left=Deletion(root->left,val);
		}else{
			if(root->left==NULL){
				Node*temp=root->right;
				delete root;
				return temp;
			}else if(root->right==NULL){
				Node*temp=root->left;
				delete root;
				return temp;
			}
			int max=getmax(root)->data;
			root->data=max;
			root->left	=Deletion(root->left,max);
		}
			int balance=balancefactor(root);
			root->height=1+max(getheight(root->left),getheight(root->right));
			if(balance>1&&balancefactor(root->left)>=0){
				return LLrotation(root);
			}
			if(balance>1&&balancefactor(root->left)<0){
				return LRrotation(root);
			}
			if(balance<-1&&balancefactor(root->right)<=0){
				return RRrotation(root);
			}
			if(balance<-1&&balancefactor(root->right)>0){
				return RLrotation(root);
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
	Node*search(Node*root,int val){
		if(root==NULL){
			return NULL;
		}
		if(root->data==val){
			return root;
		}
		if(root->data>val){
			return search(root->left,val);
		}else if(root->data<val){
			return search(root->right,val);
		}
	}
int main(){
 Node*root=NULL;
 root=insert(root,20);
  root=insert(root,30);
 root=insert(root,80);
 root=insert(root,60);
 root=insert(root,40);
 root=insert(root,90);
 inorder(root);
 cout<<endl;
root=Deletion(root,90);
root=Deletion(root,20);
Node*y=search(root,80);
cout<<endl;
if(y!=NULL){
	cout<<y->data<<endl;
}
//  inorder(root);

}
