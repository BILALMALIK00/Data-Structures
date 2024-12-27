#include <iostream>

class HashTableEntry
{
public:
    int key;
    int value;
    bool deleted;

    HashTableEntry(int k, int v) : key(k), value(v), deleted(false) {}
};

class HashMapTable
{
private:
    static const int TABLE_SIZE = 10;
    HashTableEntry **table;

public:
    HashMapTable()
    {
        table = new HashTableEntry *[TABLE_SIZE]();
    }

    int HashFunc(int k)
    {
        return k % TABLE_SIZE;
    }

    void Insert(int k, int v)
    {
        int hash = HashFunc(k);
        int i = 0;

        while (table[hash] != NULL && (!table[hash]->deleted && table[hash]->key != k))
        {
            i++;
            hash = (HashFunc(k) + i * i) % TABLE_SIZE;
        }

        if (table[hash] != NULL && !table[hash]->deleted)
        {
            table[hash]->value = v;
            return;
        }

        delete table[hash];
        table[hash] = new HashTableEntry(k, v);
    }

    int SearchKey(int k)
    {
        int hash = HashFunc(k);
        int i = 0;

        while (table[hash] != NULL)
        {
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                return table[hash]->value;
            }
            i++;
            hash = (HashFunc(k) + i * i) % TABLE_SIZE;
        }

        return -1;
    }

    void Remove(int k)
    {
        int hash = HashFunc(k);
        int i = 0;

        while (table[hash] != NULL)
        {
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                table[hash]->deleted = true;
                return;
            }
            i++;
            hash = (HashFunc(k) + i * i) % TABLE_SIZE;
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL && !table[i]->deleted)
            {
                std::cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << std::endl;
            }
            else
            {
                std::cout << "Index " << i << ": Empty" << std::endl;
            }
        }
    }

    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                delete table[i];
            }
        }
        delete[] table;
    }
};

int main()
{
    HashMapTable hashTable;

    hashTable.Insert(0, 10);
    hashTable.Insert(2, 20);
    hashTable.Insert(11, 30);

    std::cout << "Hash Table After Insertions:" << std::endl;
    hashTable.PrintTable();

    int value = hashTable.SearchKey(2);
    if (value != -1)
    {
        std::cout << "Value for key 2: " << value << std::endl;
    }
    else
    {
        std::cout << "Key 2 not found." << std::endl;
    }

    hashTable.Remove(2);

    std::cout << "Hash Table After Removal:" << std::endl;
    hashTable.PrintTable();

    return 0;
}

