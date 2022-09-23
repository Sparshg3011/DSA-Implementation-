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
bool isBSTUtil(node* root, node *prev)
{
    // traverse the tree in inorder fashion and 
    // keep track of prev node
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
          return false;
    
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
          return false;
    
        prev = root;
    
        return isBSTUtil(root->right, prev);
    }
    
    return true;
}

node *BSTsearch(node *root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return BSTsearch(root->left, key);
    }
    else
    {
        return BSTsearch(root->right, key);
    }

}

bool checkBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!checkBST(root->left))
        {
            return false;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        return checkBST(root->right);
    }

    else
    {
        return true;
    }
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

   node *ptr = BSTsearch(root, 30);
   if(ptr != NULL)
   {
       cout<<"Element found"<<endl;
   }
   else
   {
       cout<<"Elemet not found"<<endl;
   }

    return 0;
}