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

void preordertraversal(node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

int main()
{
    node *root = createnode(30);
    node *p1 = createnode(29);
    node *p2 = createnode(28);
    node *p3 = createnode(27);
    node *p4 = createnode(26);
    root->left = p1;
    root->right = p2;
    p1->left= p3;
    p2->right = p4;

    
    preordertraversal(root);

    return 0;
}