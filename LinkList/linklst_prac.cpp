#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(NULL), next(NULL) {}
};

class DoublycircularLL {
public:
    Node* head = NULL;
    Node* tail = NULL;

    void insertattail(int v) {
        Node* temp = new Node(v);
        if (head == NULL) {
            head = temp;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        }
    }

    void insertfromhead(int v) {
        Node* temp = new Node(v);
        if (head == NULL) {
            head = temp;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
            tail->next = head;
            head->prev = tail;
        }
    }

    void insertatanyposition(int pos, int val) {
        if (pos == 1) {
            insertfromhead(val);
            return;
        }
        if (pos < 1) {
            cout << "Invalid Position" << endl; // start from 1
            return;
        }

        int cnt = 1;
        Node* curr = head;
        while (curr->next != head && cnt < pos) {
            curr = curr->next;
            cnt++;
        }

        if (cnt < pos) {
            cout << "Invalid Position" << endl;
            return;
        }

        Node* newnode = new Node(val);
        newnode->next = curr;
        newnode->prev = curr->prev;
        curr->prev->next = newnode;
        curr->prev = newnode;

        if (curr == head) {
            head = newnode; // Update head if inserting at the start
        }
    }

    void deletion(int pos) {
        if (pos < 1) {
            cout << "OUT OF BOUND" << endl;
            return;
        }
        int cnt = 1;
        Node* curr = head;

        if (head == NULL) {
            cout << "LIST IS EMPTY" << endl;
            return;
        }

        if (pos == 1) {
            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
                cout << "Deleted" << endl;
            } else {
                curr = head;
                head = head->next;
                tail->next = head;
                head->prev = tail;
                delete curr;
                cout << "Deleted" << endl;
            }
            return;
        }

        while (cnt < pos && curr->next != head) {
            curr = curr->next;
            cnt++;
        }

        if (cnt < pos) {
            cout << "OUT OF BOUND KINDLY PROVIDE CORRECT POSITION TO DELETE" << endl;
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if (curr == tail) {
            tail = curr->prev; // Update tail if necessary
        }

        delete curr;
        cout << "Deleted" << endl;
    }

    void displayfromhead() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayfromtail() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail;
        do {
            cout << temp->data << "->";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }
};

int main() {
    DoublycircularLL l1;
    l1.insertattail(3);
    l1.displayfromhead();
    l1.insertattail(6);
    l1.displayfromhead();
    l1.displayfromtail();
    l1.insertfromhead(8);
    l1.displayfromhead();
    DoublycircularLL l2;
    l2.insertfromhead(7);
    l2.insertfromhead(9);
    l2.displayfromhead();
    DoublycircularLL l3;
    l3.insertatanyposition(1, 1);
    l3.insertatanyposition(2, 2);
    l3.insertatanyposition(3, 3);
    l3.insertatanyposition(4, 5);
    l3.insertatanyposition(5, 5);
    l3.insertatanyposition(6, 3);
    l3.insertattail(6);
    l3.insertfromhead(4);
    l3.displayfromhead();
    l3.deletion(6);
    l3.displayfromhead();
    l3.deletion(1);
    l3.displayfromhead();
    l3.deletion(2);
    l3.displayfromhead();
    cout << "head:" << (l3.head ? to_string(l3.head->data) : "NULL") << endl; // checking
    cout << "Tail:" << (l3.tail ? to_string(l3.tail->data) : "NULL") << endl;
    l3.insertattail(11);
    l3.insertatanyposition(1, 10);
    l3.insertfromhead(1);
    l3.insertatanyposition(8, 90);
    l3.displayfromhead();
    cout << "head:" << (l3.head ? to_string(l3.head->data) : "NULL") << endl; // checking
    cout << "Tail:" << (l3.tail ? to_string(l3.tail->data) : "NULL") << endl;
    DoublycircularLL l4;
    l4.insertatanyposition(1, 20);
    l4.deletion(1);
}

