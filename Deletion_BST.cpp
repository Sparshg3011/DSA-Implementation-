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

node *creatnode(int val)
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

node *sucessor(node *root)
{
    node *ptr = root;
    if(ptr && ptr->left != NULL)
    {
        ptr  = ptr->left;
    }
    return ptr;
}

node *deletionBST(node *root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data > key)
    {
        root->left = deletionBST(root->left, key);
    }
    else if(root->data < key)
    {
        root->right = deletionBST(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if(root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
    node *temp = sucessor(root->left);
    root->data = temp->data;
    root->right = deletionBST(root->right, temp->data);
    }
    return root;
}

int main()
{
    node *root = creatnode(30);
    node *p1 = creatnode(23);
    node *p2 = creatnode(35);
    node *p3 = creatnode(22);
    node *p4 = creatnode(28);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    inordertraversal(root);
    deletionBST(root, 35);
    cout<<endl;
    inordertraversal(root);
}