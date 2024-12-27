
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class QueueNode {
public:
    Node* data;
    QueueNode* next;

    QueueNode(Node* temp) {
        data = temp;
        next = NULL;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(Node* temp) {
        QueueNode* newNode = new QueueNode(temp);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node* dequeue() {
        if (front == NULL) {
            return NULL;
        }
        QueueNode* temp = front;
        front = front->next;
        Node* node = temp->data;
        delete temp;
        return node;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    void insert(int data) {
        if (root == NULL) {
            root = new Node(data);
            return;
        }
        
        Queue q1;
        q1.enqueue(root); // Start from the root

        while (!q1.isEmpty()) {
            Node* temp = q1.dequeue();
            cout << "Enter Data for left of " << temp->data << " (-1 for no left child): ";
            int leftData;
            cin >> leftData;
            if (leftData != -1) {
                temp->left = new Node(leftData);
                q1.enqueue(temp->left); // Enqueue the new node for further processing
            }

            // Get right child data
            cout << "Enter Data for right of " << temp->data << " (-1 for no right child): ";
            int rightData;
            cin >> rightData;
            if (rightData != -1) {
                temp->right = new Node(rightData);
                q1.enqueue(temp->right); // Enqueue the new node for further processing
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node == NULL) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
    bool iscomplete(Node*root){
    	if(root==NULL){
    		return true;
		}
		bool flag=false;
		Queue q1;
		q1.enqueue(root);
		while(!q1.isEmpty()){
			Node*temp=q1.dequeue();
			if(temp->left!=NULL){
				if(flag==true){
					return false;
				}
				q1.enqueue(temp->left);
			}else{
				flag=true;
			}
			if(temp->right!=NULL){
				if(flag==true){
					return false;
				}
				q1.enqueue(temp->right);
			}else{
				flag=true;
			}
		}
		return true;
	}
    bool isfull_tree(Node*root){
	if(root==NULL){
		return true;
	}
	if(root->left==NULL&&root->right==NULL){
		return true;
	}
	 if (root->left == NULL || root->right == NULL) {
        return false;
    }
	bool left=isfull_tree(root->left);
	bool right=isfull_tree(root->right);
	return left&&right;
}

Node*makefull(Node*root){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL&&root->right!=NULL){
		delete root->right;
		root->right=NULL;
	}
	if(root->left!=NULL&&root->right==NULL){
		delete root->left;
		root->left=NULL;
	}
	root->left=	makefull(root->left);
	 root->right=makefull(root->right);
}
};

int main() {
    Tree t1;
    t1.insert(45);
    t1.insert(23);
    t1.display(); 
    if(t1.isfull_tree(t1.root)){
    	cout<<"Full Tree"<<endl;
	}else{
		cout<<"Not Full"<<endl;
	}
    return 0;
}

