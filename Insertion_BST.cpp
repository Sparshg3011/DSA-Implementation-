#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *createnode(int val)
{
    node *ptr = new node(val);
    return ptr;
}

void inordertraversal(node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);
    }
}

void insertion(node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node *ptr = createnode(key);
    if (prev->data > key)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
}

int main()
{
    node *root = createnode(30);
    node *p1 = createnode(23);
    node *p2 = createnode(35);
    node *p3 = createnode(22);
    node *p4 = createnode(28);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    inordertraversal(root);
    insertion(root, 24);
    cout << endl
         << "After Insertion " << endl;
    inordertraversal(root);

    return 0;
}