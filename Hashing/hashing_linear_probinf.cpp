#include <iostream>

// HashTableEntry class define kiya gaya hai jo key-value pairs store karta hai.
class HashTableEntry
{
public:
    int key;      // Key store karne ke liye.
    int value;    // Value store karne ke liye.
    bool deleted; // Tombstone flag to mark deleted entries.

    // Constructor jo key aur value initialize karta hai.
    HashTableEntry(int k, int v) : key(k), value(v), deleted(false) {}
};

// HashMapTable class define ki gayi hai jo hash table implement karti hai.
class HashMapTable
{
private:
    static const int TABLE_SIZE = 10; // Hash table ka size fixed rakha gaya hai 10.
    HashTableEntry **table;           // Pointer ka array jo table ke har entry ko point karega.

public:
    // Constructor jo table ko dynamically initialize karta hai aur sari entries NULL set karta hai.
    HashMapTable()
    {
        table = new HashTableEntry *[TABLE_SIZE](); // Har entry initially NULL set ki gayi hai.
    }

    // Hash function jo key ko table ke size se mod karke hash value generate karta hai.
    int HashFunc(int k)
    {
        return k % TABLE_SIZE; // Modulo operation se index calculate hota hai.
    }

    // Insert function jo key-value pair ko table me daalta hai.
    void Insert(int k, int v)
    {
        int hash = HashFunc(k); // Key ka hash value calculate kiya.
        // Jab tak collision resolve nahi hoti, linear probing use kiya jata hai.
        while (table[hash] != NULL && (!table[hash]->deleted && table[hash]->key != k))
        {
            hash = (hash + 1) % TABLE_SIZE; // Agle index par move karte hain.
        }

        // Agar existing key ke liye entry maujood hai to naye value ke saath update karte hain.
        if (table[hash] != NULL && !table[hash]->deleted)
        {
            table[hash]->value = v; // Value update kiya.
            return;
        }

        // Nayi entry create karke hash table me daal dete hain.
        delete table[hash]; // Tombstone ya NULL slot ko free karte hain.
        table[hash] = new HashTableEntry(k, v);
    }

    // SearchKey function jo table me given key ke liye search karta hai aur value return karta hai.
    int SearchKey(int k)
    {
        int hash = HashFunc(k); // Key ka hash value calculate kiya.
        // Jab tak key nahi milti, linear probing use karte hain.
        while (table[hash] != NULL)
        {
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                return table[hash]->value; // Key ka corresponding value return kiya.
            }
            hash = (hash + 1) % TABLE_SIZE; // Agle index par move karte hain.
        }

        return -1; // Key nahi mili.
    }

    // Remove function jo table se specific key ko delete karta hai.
    void Remove(int k)
    {
        int hash = HashFunc(k); // Key ka hash value calculate kiya.
        // Jab tak entry nahi milti, linear probing use karte hain.
        while (table[hash] != NULL)
        {
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                table[hash]->deleted = true; // Entry ko tombstone marker set karte hain.
                return;
            }
            hash = (hash + 1) % TABLE_SIZE; // Agle index par move karte hain.
        }
    }

    // Function jo hash table ka pura content print karta hai.
    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL && !table[i]->deleted)
            {
                // Agar entry maujood ho aur deleted na ho to uska index, key aur value print karte hain.
                std::cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << std::endl;
            }
            else
            {
                // Agar entry NULL ya deleted ho to "Empty" print karte hain.
                std::cout << "Index " << i << ": Empty" << std::endl;
            }
        }
    }

    // Destructor jo dynamically allocated memory ko free karta hai.
    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                delete table[i]; // Har non-NULL entry ko free karte hain.
            }
        }
        delete[] table; // Table array ko free karte hain.
    }
};

int main()
{
    HashMapTable hashTable; // Hash table ka object create kiya.

    // Values insert karte hain.
    hashTable.Insert(0, 10);  // Key 0 aur Value 10 insert kiya.
    hashTable.Insert(2, 20);  // Key 2 aur Value 20 insert kiya.
    hashTable.Insert(11, 30); // Key 11 aur Value 30 insert kiya.

    // Hash table print karte hain insertions ke baad.
    std::cout << "Hash Table After Insertions:" << std::endl;
    hashTable.PrintTable();

    // Key 2 ko search karte hain.
    int value = hashTable.SearchKey(2); // Key 2 ka value search kiya.
    if (value != -1)
    {
        std::cout << "Value for key 2: " << value << std::endl; // Agar key mili to value print kiya.
    }
    else
    {
        std::cout << "Key 2 not found." << std::endl; // Agar key nahi mili to error message diya.
    }

    // Key 2 ko remove karte hain.
    hashTable.Remove(2); // Key 2 delete kiya.

    // Hash table print karte hain removal ke baad.
    std::cout << "Hash Table After Removal:" << std::endl;
    hashTable.PrintTable();

    return 0; // Program successful termination.
}
