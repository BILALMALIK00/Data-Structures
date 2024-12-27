#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int freq;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        freq = v;
        next = NULL;
    }
};

class HashTable
{
    Node **Matrix;
    int max_size;
    int elements_count;

public:
    HashTable(int m)
    {
        max_size = m;
        Matrix = new Node *[max_size];
        for (int i = 0; i < max_size; i++)
        {
            Matrix[i] = NULL;
        }
        elements_count = 0;
    }

    int hash_fun(int key)
    {
        return key % max_size;
    }

    double load_factor()
    {
        return 1.0 * elements_count / max_size;
    }

    void resize(int newsize)
    {
        Node **new_Matrix = new Node *[newsize];
        for (int i = 0; i < newsize; i++)
        {
            new_Matrix[i] = NULL;
        }

        for (int i = 0; i < max_size; i++)
        {
            Node *curr = Matrix[i];
            while (curr != NULL)
            {
                int newhash = curr->key % newsize;
                Node *next = curr->next;
                curr->next = new_Matrix[newhash];
                new_Matrix[newhash] = curr;
                curr = next;
            }
        }

        delete[] Matrix;
        Matrix = new_Matrix;
        max_size = newsize;
    }

    void insert(int k)
    {
        int hash = hash_fun(k);
        Node *curr = Matrix[hash];
        while (curr != NULL)
        {
            if (curr->key == k)
            {
                curr->freq++;
                return;
            }
            curr = curr->next;
        }

        Node *temp = new Node(k, 1);
        temp->next = Matrix[hash];
        Matrix[hash] = temp;
        elements_count++;

        if (load_factor() > 0.7)
        {
            resize(max_size * 2);
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < max_size; i++)
        {
            Node *curr = Matrix[i];
            while (curr != NULL)
            {
                Node *next = curr->next;
                delete curr;
                curr = next;
            }
        }
        delete[] Matrix;
    }

    void merge(Node *arr[], int left, int mid, int right)
    {
        int len1 = mid - left + 1;
        int len2 = right - mid;

        Node *L[len1];
        Node *R[len2];
        int k = left;
        for (int i = 0; i < len1; i++)
        {
            L[i] = arr[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++)
            R[i] = arr[k++];

        int i = 0, j = 0;
        k = left;

        while (i < len1 && j < len2)
        {
            if (L[i]->freq > R[j]->freq || (L[i]->freq == R[j]->freq && L[i]->key > R[j]->key))
            {
                arr[k++] = L[i++];
            }
            else
            {
                arr[k++] = R[j++];
            }
        }

        while (i < len1)
        {
            arr[k++] = L[i++];
        }

        while (j < len2)
        {
            arr[k++] = R[j++];
        }
    }

    void merge_sort(Node **arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            merge_sort(arr, left, mid);
            merge_sort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void print()
    {
        Node **arr=new Node*[elements_count];
        int index = 0;
        for (int i = 0; i < max_size; i++)
        {
            Node *curr = Matrix[i];
            while (curr != NULL)
            {
                arr[index++] = curr;
                curr = curr->next;
            }
        }

        merge_sort(arr, 0, index - 1);

        // Printing in sorted order
        for (int i = 0; i < index; i++)
        {
            cout << "Key: " << arr[i]->key << " Freq: " << arr[i]->freq << endl;
        }
    }
};

int main()
{
    int ratings[] = {5, 4, 3, 5, 5, 4, 2, 4, 5, 3, 3, 3};
    int size = sizeof(ratings) / sizeof(ratings[0]);

    HashTable hashTable(5);
    for (int i = 0; i < size; i++)
    {
        hashTable.insert(ratings[i]);
    }
    hashTable.print();
}

