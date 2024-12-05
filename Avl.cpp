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
            return new Node(key); // c
        }

        if (key < node->data)
        {
            node->left = insert(node->left, key); // t(n/2)
        }
        else if (key > node->data)
        {
            node->right = insert(node->right, key); // t(n/2)
        }
        node->height = 1 + max(height(node->left), height(node->right)); // c

        int balance = getBalance(node); // c

        if (balance > 1 && key < node->left->data)
        {
            return rightRotate(node); // c
        }
        if (balance < -1 && key > node->right->data)
        {
            return leftRotate(node); // c
        }
        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left); // c
            return rightRotate(node);            // c
        }
        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right); // c
            return leftRotate(node);                // c
        }
        return node;
    }

    void del(int key)
    {
        root = deleteNode(root, key);
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // code for removing when node is equal to key
            if (root->left == nullptr || root->right == nullptr)
            {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                // root has two children that are not null
                Node *temp = maxValueNode(root->left);
                root->data = temp->data;
                root->left = deleteNode(root->left, temp->data);
            }
            if (root == nullptr)
            {
                return root;
            }

            root->height = 1 + max(height(root->left), height(root->right));

            int balance = getBalance(root);

            if (balance > 1 && getBalance(root->left) >= 0)
            {
                return rightRotate(root);
            }
            if (balance > 1 && getBalance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && getBalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            if (balance < -1 && getBalance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }
        
    }

    Node *maxValueNode(Node *node)
    {
        Node *current = node;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }
};