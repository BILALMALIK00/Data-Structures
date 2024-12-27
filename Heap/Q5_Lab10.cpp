#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char letter;
    int freq;
    Node* left;
    Node* right;

    Node(int fre, char c) {
        left = NULL;
        right = NULL;
        freq = fre;
        letter = c;
    }
};

class minheap {
public:
    Node** heap;
    int max_size;
    int size;
    minheap(int max_size) {
        heap = new Node*[max_size];
        size = 0;
    }
   // Inserting a node into the heap (1-based index)
    void insert(Node* node) {
    	if (size >= max_size) {
            cout << "Heap is full!" << endl;
            return;
        }
        size++;
        int index = size;
        heap[index] = node;

        while (index > 1) {
            int parent = index / 2;
            if (heap[parent]->freq > heap[index]->freq) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    Node* getmin() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return NULL;
        }

        Node* minnode = heap[1];
        heap[1] = heap[size];
        size--;

        int i = 1;
        while (i <= size) {
            int smallest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= size && heap[left]->freq < heap[smallest]->freq) {
                smallest = left;
            }
            if (right <= size && heap[right]->freq < heap[smallest]->freq) {
                smallest = right;
            }
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }

        return minnode;
    }

    ~minheap() {
        for (int i = 1; i <= size; i++) {
            delete heap[i];
        }
        delete[] heap;
    }
};

void getfrequency(string text, int freq[]) {
    for (int i = 0; i < 256; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < text.size(); i++) {
        freq[text[i]]++;
    }
}

Node* Huffman_Tree(string text) {
    int freq[256];
    getfrequency(text, freq);
    minheap h1(256);

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            Node* temp = new Node(freq[i], char(i));
            h1.insert(temp);
        }
    }

    while (h1.size > 1) {
        Node* left = h1.getmin();
        Node* right = h1.getmin();
        Node* newroot = new Node(left->freq + right->freq, '\0');
        newroot->left = left;
        newroot->right = right;
        h1.insert(newroot);
    }

    return h1.getmin(); 
}

void HuffmanEncoding(Node* root, string code, string* codes) {
    if (root == NULL) {
        return;
    }
    if (root->letter != '\0') {
        codes[root->letter] = code;
    }
    HuffmanEncoding(root->left, code +"0", codes);
    HuffmanEncoding(root->right, code +"1", codes);
}

string encode(string text, string* codes) {
    string encodedString = "";
    for (int i = 0; i < text.length(); i++) {
        encodedString += codes[text[i]];  
    }
    return encodedString;
}

string decode(string encodedString, Node* root) {
    string decodedString = "";
    Node* current = root;
    for (int i = 0; i < encodedString.length(); i++) {
        if (encodedString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            decodedString += current->letter;
            current = root; 
        }
    }
    return decodedString;
}

int main() {
    string text="Bilal";
    Node* root = Huffman_Tree(text);
    string codes[256];
    HuffmanEncoding(root, "", codes);
    cout << "Huffman Codes: " << endl;
    for (int i = 0; i < 256; i++) {
        if (codes[i] != "") {
            cout << char(i) << ": " << codes[i] << endl;
        }
    }
    string encodedString = encode(text, codes);
    cout << "\nEncoded String: " << encodedString << endl;

    string decodedString = decode(encodedString, root);
    cout << "\nDecoded String: " << decodedString << endl;
}

