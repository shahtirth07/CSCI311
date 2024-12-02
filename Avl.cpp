#include <iostream>

using namespace std;

class Avl
{
private:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;
        int height;
        Node(int d)
        {
            data = d;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }

        if (key < node->data)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = insert(node->right, key);
        }
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->data)
        {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
};