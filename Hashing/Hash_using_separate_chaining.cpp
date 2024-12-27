#include<iostream>
using namespace std;

class hash_entry{
public:
    int key;
    int val;
    hash_entry* next;
public:
    hash_entry(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
};

class HashTable{
public:
    int max_size;
    hash_entry** Table;
    int element_count;

    HashTable(int size = 10){  // Default size is 10 if not specified
        max_size = size;
        Table = new hash_entry*[max_size];
        for (int i = 0; i < max_size; ++i)
            Table[i] = NULL;
        element_count = 0;
    }

    int hash_func(int key){
        return key % max_size;
    }

    double Loadfactor(){
        return 1.0 * element_count / max_size;
    }

    void resize_table(int newsize){
        hash_entry** new_table = new hash_entry*[newsize];
        for (int i = 0; i < newsize; ++i)
            new_table[i] = NULL;

        for (int i = 0; i < max_size; ++i){
            hash_entry* curr = Table[i];
            while (curr != NULL){
                int newhash = curr->key % newsize;
                hash_entry* next = curr->next;
                curr->next = new_table[newhash];
                new_table[newhash] = curr;
                curr = next;
            }
        }

        delete[] Table;
        Table = new_table;
        max_size = newsize;
    }

    void insert(int k, int v){
        int hash = hash_func(k);
        hash_entry* newentry = new hash_entry(k, v);

        if (Table[hash] == NULL){
            Table[hash] = newentry;
        } else {
            hash_entry* curr = Table[hash];
            while (curr->next != NULL){
                curr = curr->next;
            }
            curr->next = newentry;
        }
        element_count++;

        if (Loadfactor() > 0.7){
            int newsize = max_size * 2;
            resize_table(newsize);
        }
    }

    int search(int k){
        int hash = hash_func(k);
        hash_entry* curr = Table[hash];
        while (curr != NULL){
            if (curr->key == k){
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int k){
        int hash = hash_func(k);
        hash_entry* curr = Table[hash];
        hash_entry* prev = NULL;
        while (curr != NULL && curr->key != k){
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL){
            if (prev != NULL){
                prev->next = curr->next;
            } else {
                Table[hash] = curr->next;
            }
            delete curr;
            element_count--;
        }
    }

    void print(){
        for (int i = 0; i < max_size; i++){
            cout << "index " << i << ":";
            hash_entry* curr = Table[i];
            while (curr != NULL){
                cout << "key=" << curr->key << " value=" << curr->val << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }

    ~HashTable(){
        for (int i = 0; i < max_size; i++){
            hash_entry* curr = Table[i];
            while (curr != NULL){
                hash_entry* next = curr->next;
                delete curr;
                curr = next;
            }
        }
        delete[] Table;
    }
};

int main(){
    HashTable ht(10);
    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(11, 300);

    ht.print();

    cout << "Search key 1: " << ht.search(1) << endl;
    cout << "Search key 11: " << ht.search(11) << endl;

    ht.remove(1);
    cout << "After removal of key 1:" << endl;
    ht.print();

    return 0;
}
