#include<iostream>
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

node *createnode(node *ptr, int val)
{
    ptr = new node(val);
    return ptr;
}

int main()
{
    node *p = createnode(p, 20);
    node *p1 = createnode(p1, 30);
    node *p2 = createnode(p2, 40);
    p->left = p1;
    p->right = p2;

    return 0;
}

