#include <iostream>
using namespace std;

class hash_entry {
public:
    string key;
    int freq;
    bool isdeleted;
    hash_entry(string k, int f) {
        key = k;
        freq = f;
        isdeleted = false;
    }
};

class Hash_Table {
public:
    hash_entry** table;
    int max_size;

    Hash_Table(int size = 11) {
        max_size = size;
        table = new hash_entry*[max_size]();
    }

    int hash_func1(string key) {
        int hash = 0;
        for (int i = 0; i < key.size(); i++) {
            char ch = key[i];
            hash = (hash * 31 + ch) % max_size;
        }
        return hash;
    }

    int hash_func2(string key) {
        int hash = 0;
        for (int i = 0; i < key.size(); i++) {
            char ch = key[i];
            hash = (hash * 31 + ch) % max_size;
        }
        return 7 - (hash % 7);
    }

    int doublehash(string k, int i) {
        return (hash_func1(k) + i * hash_func2(k)) % max_size;
    }

    void insert(string k) {
        int i = 0;
        int hash = hash_func1(k);
        while (table[hash] != NULL && !table[hash]->isdeleted) {
            if (table[hash]->key == k) {
                table[hash]->freq++;
                return;
            }
            i++;
            hash = doublehash(k, i);
        }
        table[hash] = new hash_entry(k, 1);
    }

    void merge(hash_entry** arr, int s, int e) {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        hash_entry* arr1[len1];
        hash_entry* arr2[len2];
        int k = s;
        for (int i = 0; i < len1; i++) {
            arr1[i] = arr[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++) {
            arr2[i] = arr[k++];
        }

        int i = 0, j = 0;
        k = s;
        while (i < len1 && j < len2) {
            if (arr1[i]->freq > arr2[j]->freq || (arr1[i]->freq == arr2[j]->freq && arr1[i]->key < arr2[j]->key)) {
                arr[k++] = arr1[i++];
            } else {
                arr[k++] = arr2[j++];
            }
        }
        while (i < len1) {
            arr[k++] = arr1[i++];
        }
        while (j < len2) {
            arr[k++] = arr2[j++];
        }
    }

    void merge_sort(hash_entry* arr[], int s, int e) {
        if (s >= e) {
            return;
        }
        int mid = (s + e) / 2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid + 1, e);
        merge(arr, s, e);
    }

    void print() {
        hash_entry* entries[max_size];
        int index = 0;
        for (int i = 0; i < max_size; i++) {
            if (table[i] != NULL && !table[i]->isdeleted) {
                entries[index++] = table[i];
            }
        }

        merge_sort(entries, 0, index - 1);

        for (int i = 0; i < index; i++) {
            cout << "Key: " << entries[i]->key << " Freq: " << entries[i]->freq << endl;
        }
    }

    ~Hash_Table() {
        for (int i = 0; i < max_size; i++) {
            delete table[i];
        }
        delete[] table;
    }
};

int main() {
    Hash_Table h1;
    h1.insert("Apple");
    h1.insert("banana");
    h1.insert("orange");
    h1.insert("kiwi");
    h1.insert("Apple");
    h1.insert("kiwi");
    h1.insert("Apple");

    h1.print();

    return 0;
}

