// Quadratic Probing
#include <iostream>
using namespace std;
class HashTable
{
private:
    int *table;
    int capacity;

    int hash(int key)
    {
        return key % capacity;
    }

public:
    HashTable(int size)
    {
        capacity = size;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = -1;
        }
    }

    ~HashTable()
    {
        delete[] table;
    }

    // linear probing
    bool insertLinearProbing(int key)
    {
        int index = hash(key);
        int originalIndex = index;
        do
        {
            if (table[index] == -1)
            {
                table[index] = key;
                return true;
            }
            index = (index + 1) % capacity;
        } while (index != originalIndex);
        return false;
    }

    // delete linear probing
    bool deleteLinearProbing(int key)
    {
        int index = hash(key);
        int originalIndex = index;
        do
        {
            if (table[index] == -1)
            {
                return false;
            }
            else if (table[index] == key)
            {
                table[index] = -2;
                return true;
            }
            index = (index + 1) % capacity;
        } while (index != originalIndex);
        return false;
    }

    // quadratic probing
    bool insertQuadraticProbing(int key)
    {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;
        do
        {
            int newIndex = (index + i * i) % capacity;
            if (table[newIndex] == -1)
            {
                table[newIndex] = key;
                return true;
            }
            i++;
        } while (index != originalIndex && i < capacity);
        return false;
    }

    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << table[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    HashTable ht(10);
    ht.insertLinearProbing(10);
    ht.insertLinearProbing(20);
    ht.insertLinearProbing(30);
    ht.insertLinearProbing(40);
    ht.insertLinearProbing(50);
    ht.deleteLinearProbing(20);
    ht.print();
    return 0;
}