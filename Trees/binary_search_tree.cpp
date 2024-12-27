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
    Node* treeNode;
    QueueNode* next;
    QueueNode(Node* node) {
        treeNode = node;
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

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(Node* node) {
        QueueNode* temp = new QueueNode(node);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    Node* dequeue() {
        if (isEmpty()) {
            return NULL;
        }
        QueueNode* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        Node* node = temp->treeNode;
        delete temp;
        return node;
    }

    Node* getFront() {
        if (isEmpty()) {
            return NULL;
        }
        return front->treeNode;
    }
};

void level_order_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue q1;
    q1.enqueue(root);
    q1.enqueue(NULL);  

    while (!q1.isEmpty()) {
        Node* temp = q1.dequeue();
        if (temp == NULL) {
            cout << endl;
            if (!q1.isEmpty()) {
                q1.enqueue(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q1.enqueue(temp->left);
            }
            if (temp->right) {
                q1.enqueue(temp->right);
            }
        }
    }
}

Node* insertintobst(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertintobst(root->right, data);
    } else {
        root->left = insertintobst(root->left, data);
    }
    return root;
}

void takeinput(Node*& root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = insertintobst(root, data);
        cout << "Enter next data (-1 to stop): ";
        cin >> data;
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Binary search to find a node with the target value
Node* binary_search(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == target) {
        return root;
    }
    if (root->data > target) {
        return binary_search(root->left, target);
    } else {
        return binary_search(root->right, target);
    }
}

Node* getmin(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL) {
        return root;  
    }
    return getmin(root->left); 
}

Node* getmax(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->right == NULL) {
        return root;
    }
    return getmax(root->right);
}

Node* getPredecessor(Node* root, int val) {
    Node* pred = NULL;
    while (root != NULL) {
        if (val > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

Node* getSuccessor(Node* root, int val) {
    Node* targetNode = binary_search(root, val);
    if (targetNode == NULL) {
        return NULL; 
    }

    // Case 1: Node has a right child
    if (targetNode->right != NULL) {
        return getmin(targetNode->right);
    }

    // Case 2: No right child, backtrack to find the successor
    Node* succ = NULL;
    Node* ancestor = root;

    while (ancestor != targetNode) {
        if (targetNode->data < ancestor->data) {
            succ = ancestor;  // This might be a successor
            ancestor = ancestor->left;  // Move left
        } else {
            ancestor = ancestor->right;  // Move right
        }
    }
    return succ;
}
Node*Deletion(Node*root,int val){
	if(root==NULL){
		return root;
	}
	if(root->data==val){
		//case 1: 0 child
		if(root->left==NULL&&root->right==NULL){
			delete root;
			return NULL;
		}
		//case 2: 1 child
		if(root->left==NULL&&root->right!=NULL){
			Node*temp=root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL&&root->right==NULL){
			Node*temp=root->left;
			delete root;
			return temp;
		}
		//case 3: 2 child
		if(root->left!=NULL&&root->right!=NULL){
		int max=getmax(root->left)->data;
		//replace root data with max then recursive call to delete that max value which will become 0 child or 1 child case
		root->data=max;
		root->left=Deletion(root->left,max);
		return root;
		}
	}
	else if(root->data>val){
			root->left=Deletion(root->left,val);
			return root;
		}else{
			root->right=Deletion(root->right,val);
			return root;
		}
}

int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeinput(root);  

    cout << "Level-order Traversal of the BST:" << endl;
    level_order_traversal(root);  

    cout << endl << "Inorder Traversal of the BST:" << endl;
    inorder(root);  

    int search_val = 12;
    Node* temp = binary_search(root, search_val);
    if (temp != NULL) {
        cout << endl << "Node with value " << search_val << " found." << endl;
    } else {
        cout << endl << "Node with value " << search_val << " not found." << endl;
    }

    Node* min_node = getmin(root);
    if (min_node != NULL) {
        cout << "Minimum value in the BST is: " << min_node->data << endl;
    } else {
        cout << "The tree is empty, no minimum value." << endl;
    }

    Node* max_node = getmax(root);
    if (max_node != NULL) {
        cout << "Maximum value in the BST is: " << max_node->data << endl;
    } else {
        cout << "The tree is empty, no maximum value." << endl;
    }  

    int predecessor_val = 12; 
    Node* predecessor_node = getPredecessor(root, predecessor_val);
    if (predecessor_node != NULL) {
        cout << "Predecessor of " << predecessor_val << " is: " << predecessor_node->data << endl;
    } else {
        cout << "No predecessor found for " << predecessor_val << "." << endl;
    }

    int successor_val = 20; 
    Node* successor_node = getSuccessor(root, successor_val);
    if (successor_node != NULL) {
        cout << "Successor of " << successor_val << " is: " << successor_node->data << endl;
    } else {
        cout << "No successor found for " << successor_val << "." << endl;
    }
	int dele=25;
	Node*news=Deletion(root,dele);
	cout<<endl;
	 cout << "Level-order Traversal of the BST:" << endl;
	inorder(news);
    return 0;
}

