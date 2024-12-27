#include <iostream>

// HashTableEntry class: Yeh class ek entry represent karti hai hash table mein.
// Har entry key, value aur ek deleted flag rakhti hai jo identify karta hai agar entry ko remove kiya gaya ho.
class HashTableEntry {
public:
    int key;       // Entry ki unique key
    int value;     // Entry ka corresponding value
    bool deleted;  // Deleted flag jo batata hai ke entry delete hui hai ya nahi

    // Constructor: Naye key aur value ke saath ek entry create karta hai
    HashTableEntry(int k, int v) : key(k), value(v), deleted(false) {}
};

// HashMapTable class: Yeh class hash table implement karti hai jo double hashing ka use karke collision resolve karti hai.
class HashMapTable {
private:
    static const int TABLE_SIZE = 11;   // Table ka fixed size (prime number rakha gaya hai for better hashing)
    HashTableEntry** table;            // Pointer array jo table ke entries ko store karega

    // HashFunc1: Primary hash function jo key ka mod TABLE_SIZE karta hai
    int HashFunc1(int k) {
        return k % TABLE_SIZE;
    }

    // HashFunc2: Secondary hash function jo double hashing ke liye use hota hai
    // Yeh ek different modulus ka use karta hai (prime number 8 se mod kiya gaya hai)
    int HashFunc2(int k) {
        return 7 - (k % 7);
    }

public:
    // Constructor: Hash table ko initialize karta hai, pehle sab slots null set kiye jate hain
    HashMapTable() {
        table = new HashTableEntry*[TABLE_SIZE]();
    }

    // DoubleHashFunc: Dono hash functions ka use karke double hashing karta hai
    // Yeh key aur attempt (i) ke basis pe ek unique index generate karta hai
    int DoubleHashFunc(int k, int i) {
        return (HashFunc1(k) + i * HashFunc2(k)) % TABLE_SIZE;
    }

    // Insert function: Table mein ek nayi key-value pair insert karta hai
    void Insert(int k, int v) {
        int i = 0;  // Attempt counter (double hashing ke liye)
        int hash = HashFunc1(k);  // Primary hash function ka result

        // Jab tak table ka slot free na ho ya entry delete na ho, double hashing lagao
        while (table[hash] != nullptr && !table[hash]->deleted) {
            i++;  // Next attempt
            hash = DoubleHashFunc(k, i);  // Double hashing ka naya index
        }

        // Nayi entry create karke table ke calculated hash position par rakh do
        table[hash] = new HashTableEntry(k, v);
    }

    // SearchKey function: Ek given key ko table mein dhoondhta hai aur uska value return karta hai
    int SearchKey(int k) {
        int i = 0;  // Attempt counter
        int hash = HashFunc1(k);  // Primary hash function ka result

        // Jab tak slot null na ho, search karte raho
        while (table[hash] != nullptr) {
            // Agar key match ho jaye aur entry delete na ho, value return karo
            if (!table[hash]->deleted && table[hash]->key == k) {
                return table[hash]->value;
            }
            i++;  // Next attempt
            hash = DoubleHashFunc(k, i);  // Double hashing ka naya index
        }

        return -1;  // Agar key nahi mili toh -1 return karo
    }

    // Remove function: Ek given key ko table se remove karta hai (deleted flag ko true set karta hai)
    void Remove(int k) {
        int i = 0;  // Attempt counter
        int hash = HashFunc1(k);  // Primary hash function ka result

        // Jab tak slot null na ho, key dhoondte raho
        while (table[hash] != nullptr) {
            // Agar key match ho jaye aur entry delete na ho, deleted flag true set karo
            if (!table[hash]->deleted && table[hash]->key == k) {
                table[hash]->deleted = true;  // Entry ko delete mark kar diya
                return;
            }
            i++;  // Next attempt
            hash = DoubleHashFunc(k, i);  // Double hashing ka naya index
        }
    }

    // PrintTable function: Table ka content print karta hai (occupied slots aur empty slots)
    void PrintTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            // Agar entry exist karti hai aur deleted nahi hai toh uska data print karo
            if (table[i] != nullptr && !table[i]->deleted) {
                std::cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << std::endl;
            } else {
                // Agar slot empty hai ya entry delete ho chuki hai toh "Empty" print karo
                std::cout << "Index " << i << ": Empty" << std::endl;
            }
        }
    }

    // Destructor: Table ke saare dynamically allocated memory ko free karta hai
    ~HashMapTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != nullptr) {
                delete table[i];  // Har entry ko delete karo
            }
        }
        delete[] table;  // Array of pointers ko free karo
    }
};

// Main function: Hash table ka demonstration karta hai
int main() {
    HashMapTable hashTable;

    // Insertions: Table mein kuch keys aur values insert kar rahe hain
    hashTable.Insert(20, 10);
    hashTable.Insert(34, 20);
    hashTable.Insert(45, 30);
    hashTable.Insert(70, 40);
    hashTable.Insert(56, 50);

    // Table ka content print karte hain
    std::cout << "Hash Table After Insertions:" << std::endl;
    hashTable.PrintTable();

    // Searching: Ek specific key (2) ko table mein dhoondte hain
    int value = hashTable.SearchKey(2);
    if (value != -1) {
        std::cout << "Value for key 2: " << value << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    // Removing: Key 2 ko table se delete karte hain
    hashTable.Remove(2);

    // Table ka content remove operation ke baad print karte hain
    std::cout << "Hash Table After Removal:" << std::endl;
    hashTable.PrintTable();

    return 0;  // Program successfully khatam hota hai
}
