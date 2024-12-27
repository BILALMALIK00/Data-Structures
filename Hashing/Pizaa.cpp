#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int key;  
    int height;
    string name;
    int deliveryTime;
    int vehicleSpeed;

    Node(int va, string n, int dt, int vs) {
        key = va;
        name = n;
        deliveryTime = dt;
        vehicleSpeed = vs;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

Node* getmax(Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return getmax(root->right);
}

int getheight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int balancefactor(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

Node* LLrotation(Node* root) {
    Node* rootl = root->left;
    root->left = rootl->right;
    rootl->right = root;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    rootl->height = 1 + max(getheight(rootl->left), getheight(rootl->right));
    return rootl;
}

Node* RRrotation(Node* root) {
    Node* rootr = root->right;
    root->right = rootr->left;
    rootr->left = root;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    rootr->height = 1 + max(getheight(rootr->left), getheight(rootr->right));
    return rootr;
}

Node* LRrotation(Node* root) {
    root->left = RRrotation(root->left);
    return LLrotation(root);
}

Node* RLrotation(Node* root) {
    root->right = LLrotation(root->right);
    return RRrotation(root);
}

Node* insert(Node* root, int val, string name, int deliveryTime, int vehicleSpeed) {
    if (root == NULL) {
        root = new Node(val, name, deliveryTime, vehicleSpeed);
        return root;
    }
    if (root->key > val) {
        root->left = insert(root->left, val, name, deliveryTime, vehicleSpeed);
    } else if (root->key < val) {
        root->right = insert(root->right, val, name, deliveryTime, vehicleSpeed);
    } else {
        return root;
    }
    int factor = balancefactor(root);
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    if (factor > 1 && root->left->key > val) {
        return LLrotation(root);
    }
    if (factor > 1 && root->left->key < val) {
        return LRrotation(root);
    }
    if (factor < -1 && root->right->key < val) {
        return RRrotation(root);
    }
    if (factor < -1 && root->right->key > val) {
        return RLrotation(root);
    }
    return root;
}

Node* Deletion(Node* root, int val) {//deleting by delivery time
    if (root == NULL) {
        return NULL;
    }
    if (root->deliveryTime < val) {
        root->right = Deletion(root->right, val);
    } else if (root->deliveryTime > val) {
        root->left = Deletion(root->left, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        int max = getmax(root)->deliveryTime;
        root->deliveryTime = max;
        root->left = Deletion(root->left, max);
    }
    int balance = balancefactor(root);
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    if (balance > 1 && balancefactor(root->left) >= 0) {
        return LLrotation(root);
    }
    if (balance > 1 && balancefactor(root->left) < 0) {
        return LRrotation(root);
    }
    if (balance < -1 && balancefactor(root->right) <= 0) {
        return RRrotation(root);
    }
    if (balance < -1 && balancefactor(root->right) > 0) {
        return RLrotation(root);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->key << " " << root->name << " " << root->deliveryTime << " " << root->vehicleSpeed << endl;
    inorder(root->right);
}

void searchbydeliverytime(Node* root, int min, int max) {
    if (root == NULL) {
        return;
    }
   
        searchbydeliverytime(root->left, min, max);

    if (root->deliveryTime >= min && root->deliveryTime <= max) {
        cout << root->name << " " << root->deliveryTime << endl;
    }

        searchbydeliverytime(root->right, min, max);
}

void searchbyspeed(Node* root, int min, int max) {
    if (root == NULL) {
        return;
    }

    if (root->vehicleSpeed > min) {
        searchbyspeed(root->left, min, max);
    }
    if (root->vehicleSpeed >= min && root->vehicleSpeed <= max) {
        cout << root->name << " " << root->vehicleSpeed << endl;
    }

    if (root->vehicleSpeed < max) {
        searchbyspeed(root->right, min, max);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 20, "John", 30, 50);
    root = insert(root, 30, "Ali", 45, 60);
    root = insert(root, 80, "B", 25, 40);
    root = insert(root, 60, "Dve", 35, 55);
    root = insert(root, 40, "Ev", 40, 45);
    root = insert(root, 90, "Fra", 50, 60);
    
    cout << "Inorder Traversal:" << endl;
    	root=Deletion(root,35);
    inorder(root);
    cout << endl;
//	root=deletion(root,35);
    cout << "Search by Delivery Time (30 to 50):" << endl;
    searchbydeliverytime(root, 30, 50);
    cout << endl;

    cout << "Search by Vehicle Speed (50 to 60):" << endl;
    searchbyspeed(root, 50, 60);
    cout << endl;
}

