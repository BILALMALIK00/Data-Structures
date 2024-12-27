#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
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
                curr->value++;
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
    Node **get_elements(int &count)
    {
        Node **elements = new Node *[elements_count];
        int index = 0;

        for (int i = 0; i < max_size; i++)
        {
            Node *curr = Matrix[i];
            while (curr != NULL)
            {
                elements[index++] = curr;
                curr = curr->next;
            }
        }

        count = elements_count;
        return elements;
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
};
void merge(Node **arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Node **L = new Node *[n1];
    Node **R = new Node *[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i]->value > R[j]->value ||
            (L[i]->value == R[j]->value && L[i]->key > R[j]->key))
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
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

int main()
{
    int ratings[] = {5, 4, 3, 5, 5, 4, 2, 4, 5, 3, 3, 3};
    int size = sizeof(ratings) / sizeof(ratings[0]);

    HashTable hashTable(5);
    for (int i = 0; i < size; i++)
    {
        hashTable.insert(ratings[i]);
    }

    int elementCount;
    Node **elements = hashTable.get_elements(elementCount);

    merge_sort(elements, 0, elementCount - 1);

    cout << "Sorted Ratings:\n";
    for (int i = 0; i < elementCount; i++)
    {
        cout << elements[i]->key << ": " << elements[i]->value << " occurrences\n";
    }

    delete[] elements;
    return 0;
}
