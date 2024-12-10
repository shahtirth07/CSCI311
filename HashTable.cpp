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
    bool deleteQuadraticProbing(int key)
    {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;
        do
        {
            int newIndex = (index + i * i) % capacity;
            if (table[newIndex] == -1)
            {
                return false;
            }
            else if (table[newIndex] == key)
            {
                table[newIndex] = -2;
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
    HashTable ht1(11);
    ht1.insertLinearProbing(10);
    ht1.insertLinearProbing(20);
    ht1.insertLinearProbing(30);
    ht1.insertLinearProbing(40);
    ht1.insertLinearProbing(50);
    ht1.insertLinearProbing(60);
    ht1.insertLinearProbing(70);
    ht1.insertLinearProbing(80);
    ht1.insertLinearProbing(90);
    ht1.insertLinearProbing(100);
    ht1.print();
    ht1.deleteLinearProbing(20);
    ht1.print();
    HashTable ht(11);
    ht.insertQuadraticProbing(10);
    ht.insertQuadraticProbing(20);
    ht.insertQuadraticProbing(30);
    ht.insertQuadraticProbing(40);
    ht.insertQuadraticProbing(50);
    ht.insertQuadraticProbing(60);
    ht.insertQuadraticProbing(70);
    ht.insertQuadraticProbing(80);
    ht.insertQuadraticProbing(90);
    ht.insertQuadraticProbing(100);
    ht.print();
    ht.deleteQuadraticProbing(20);
    ht.print();
    return 0;
}