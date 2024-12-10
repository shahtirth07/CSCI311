// Open Hashing
#include <iostream>
#include <list>

using namespace std;

class HshTbl
{
private:
    int bucket;
    list<int> *table;

    int hash(int key)
    {
        return (key % this->bucket);
    }

public:
    HshTbl(int capacity)
    {
        this->bucket = capacity;
        table = new list<int>[bucket];
    }

    void insertItem(int key)
    {
        int index = hash(key);
        table[index].push_back(key);
    }

    bool deleteItem(int key)
    {
        int index = hash(key);
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if (*i == key)
            {
                table[index].erase(i);
                return true;
            }
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < bucket; i++)
        {
            cout << i << ": ";
            for (list<int>::iterator it = table[i].begin(); it != table[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HshTbl h(7);
    h.insertItem(40);
    h.insertItem(50);
    h.insertItem(30);
    h.insertItem(70);
    h.insertItem(80);
    h.insertItem(60);
    h.insertItem(20);
    h.insertItem(10);
    h.insertItem(90);
    h.display();
    h.deleteItem(10);
    h.display();
    return 0;
}