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

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (root->data > data) {
        root->left = insert(root->left, data);
    } else if (root->data < data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void input(Node*& root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data !=-1) {
        root = insert(root, data);
        cout << "Enter data (-1 to stop): ";
        cin >> data;
    }
}

void convertBSTintDLL(Node* root, Node*& head) {
    if (root == NULL) {
        return;
    }
    convertBSTintDLL(root->right, head);
    root->right = head;
    if (head) {
        head->left = root;
    }
    head = root;
    convertBSTintDLL(root->left, head);
}

Node* mergeDLL(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (!head) {
                head = tail = head1;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        } else {
            if (!head) {
                head = tail = head2;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }

    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
void remove_Duplicate(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* curr = head;
    while (curr && curr->right) {
        if (curr->data == curr->right->data) {
            Node* temp = curr->right;
            Node* duplicate_next = temp->right;
            curr->right = duplicate_next;
            if (duplicate_next != NULL) {  
                duplicate_next->left = curr;
            }
            delete temp;
        } else {
            curr = curr->right;
        }
    }
}

int count_nodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->right;
    }
    return count;
}

Node* ConvertDLLintoBST(Node*& head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    Node* left = ConvertDLLintoBST(head, n / 2);
    Node* root = head;
    root->left = left;

    head = head->right; 

    root->right = ConvertDLLintoBST(head, n - n / 2 - 1);
    return root;
}

Node* MergeTwoBST(Node* root1, Node* root2) {
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

    Node* head1 = NULL;
    convertBSTintDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertBSTintDLL(root2, head2);
    head2->left = NULL;

    Node* mergedHead = mergeDLL(head1, head2);
   remove_Duplicate(mergedHead);
    int n = count_nodes(mergedHead);

    return ConvertDLLintoBST(mergedHead, n);
}

void inorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    cout << "Input BST 1:\n";
    input(root1);

    cout << "Input BST 2:\n";
    input(root2);

    Node* merged_root = MergeTwoBST(root1, root2);
    cout << "InOrder Traversal of Merged BST:\n";
    inorder_traversal(merged_root);
}

