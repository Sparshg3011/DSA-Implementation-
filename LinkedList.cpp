#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;
    
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void InsertAtTail(node* &head, int val)
{
    node * n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node * ptr = head;
    while(ptr->next != NULL)
    {
       ptr = ptr->next;
    }
    ptr->next = n;
}

void Display(node * head)
{
    node * ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"Null";
}

int main()
{
    node * head = NULL;
    InsertAtTail(head, 12);
    InsertAtTail(head, 63);
    InsertAtTail(head, 87);
    InsertAtTail(head, 34);
    InsertAtTail(head, 54);

    Display(head);

    return 0;
}