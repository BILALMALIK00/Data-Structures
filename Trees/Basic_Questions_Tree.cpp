#include<iostream>
#include<cmath>
using namespace std;
class  Node{
	public:
		int data;
		Node*left;
		Node*right;
		Nnode(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
int getheight(Node*root){
	if(root==NULL){
		return 0;
	}
	int left=getheight(root->left);
	int right=getheight(root->right);
	return  max(left,right)+1;
	}
	
	int getdiameter(Node*root){
		if(root==NULL){
			return 0;
		}
		int op1=getdiameter(root->left);
		int op2=getdiameter(root->right);
		int op3=getheight(root->left)+getheight(root->right)+1;
		return max(max(op1,op2),op3);
	}
	bool isbalanced_tree(Node*root){
		if(root==NULL){
			return true;
		}
		bool left=isbalanced_tree(root->left);
		bool right=isbalanced_tree(root->right);
		bool diff=abs(getheight(root->left)-getheight(root->right))<=1;
		if(left&&right&&diff){
			return true;
		}
		return false;
	}
	bool isidentical(Node*root1,Node*root2){
		if(root1==NULL&&root2==NULL){
			return true;
		}
		if(root1!=NULL&&root2==NULL){
			return false;
		}
		if(root1==NULL&&root2!=NULL){
			return false;
		}
		bool c1=isidentical(root1->left,root2->left);
		bool c2=isidentical(root1->right,root2->right);
		bool c3=root1->data==root2->data;
		if(c1&&c2&&c3){
			return true;
		}
		return false;
	}
int checksum(Node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL&&root->right==NULL){
		return root->data;
	}
	int leftsum=checksum(root->left);
	int rightsum=checksum(root->right);
	if(leftsum==-1||rightsum==-1){
		return -1;
	}
	if(root->data!=leftsum+rightsum){
		return -1;
	}
	return root->data+leftsum+rightsum;
}
	bool issum_tree(Node*root){
	if(checksum(root)!=-1){
		return true;
	}
	return false;
	}
	int getlength(Node*root){
		if(root==NULL){
			return 0;
		}
		//	1+getlength(root->left)+gelength(root->right); i know its correct ut iwant my approach
	int count=1;
	count+=getlength(root->left);
	count+=getlength(root->right);
	return count;
	}
	void solve(Node*root,int sum,int &maxsum,int len,int maxlen){
		if(root==NULL){
			if(len>maxlen){
				maxlen=len;
				maxsum=sum;
			}
			if(len==maxlen){
				maxsum=max(sum,maxsum);
			}
			return;
		}
		sum+=root->data;
		solve(root->left,sum,maxsum,len+1,maxlen);
		solve(root->right,sum,maxsum,len+1,maxlen);
	}
	int getmaxpathsum(Node*root){
	int len=0;
	int maxlen=0;
	int sum=0;
	int maxsum=INT_MIN;
	solve(root,sum,maxsum,len,maxlen);
	return maxsum;
	}
	
	
	
int main(){
	
}
