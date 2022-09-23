#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
int IsFull(node *&top, int val)
{
    node *n = new node(val);
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
int IsEmpty(node *&top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int Push(node *&top, int val)
{
    if (IsFull(top, val))
    {
        cout << "Stack Overflow" << endl;
        return -1;
    }
    else
    {
        node *n = new node(val);
        n->next = top;
        top = n;
        return top->data;
    }
}
int Pop(node *&top)
{
    if (IsEmpty(top))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        node *ptr = top;
        top = top->next;
        int x = ptr->data;
        delete ptr;
        return x;
    }
}
void Display(node *&top)
{
    node *ptr = top;
    int i = 1;
    while (ptr != NULL)
    {
        cout << "Element " << i << ": " << ptr->data << endl;
        ptr = ptr->next;
        i++;
    }
}
int Peek(node *&top, int pos)
{
    node *ptr = top;
    for(int i = 0; i < pos-1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int StackTop(node *&top)
{
    return top->data;
}
int StackBottom(node *&top)
{
    node *ptr = top;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{
    node *top = NULL;
    Push(top, 34);
    Push(top, 54);
    Push(top, 64);
    Push(top, 45);
    Push(top, 98);

    Display(top);

    // cout<<endl<<"After Popping the element: "<<endl;

    // Pop(top);
    // Display(top);

    int p = Peek(top, 2);
    cout<<endl<<"Element at position :"<<p<<endl;
    
    int f = StackTop(top);
    cout<<endl<<f<<endl;

    int q = StackBottom(top);
    cout<<endl<<q<<endl;
}