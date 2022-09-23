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

void InsertAtFirst(node *&head, int val)
{
    node * n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }    
    n->next = head;
    head = n;
}

void InsertInBetween(node *head, int val, int index)
{
    node * n = new node(val);
    node * ptr = head;
    int i = 0;
    while(i != index - 1)
    {
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
}

void InsertAfterNode(node *&head , int val, node * q)
{
    node * n = new node(val);
    n->next = q->next;
    q->next = n;
}

void InsertAtEnd(node *head, int val)
{
    node * n = new node(val);
    node * ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
}

void Display(node *&head)
{
    node * ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
}

int main()
{
    node * head = NULL;

    InsertAtFirst(head, 12);
    InsertAtEnd(head, 23);
    InsertAtFirst(head, 43);
    Display(head);

    cout<<endl<<"After inserting in between: "<<endl;
    
    InsertInBetween(head, 65, 1);
    Display(head);

    return 0;
}