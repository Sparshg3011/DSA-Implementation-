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

void DeleteAtFirst(node *&head)
{
    node * p = head;
    head = head->next;
    delete(p);
}

void InsertInBetween(node *&head, int val, int index)
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

void DeleteAtIndex(node *&head, int index)
{
    node * p = head;
    node * q = head->next;
    int i = 1;
    while(i != index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    delete(q);
}

void InsertAfterNode(node *&head , int val, node * q)
{
    node * n = new node(val);
    n->next = q->next;
    q->next = n;
}

void InsertAtEnd(node *&head, int val)
{
    node * n = new node(val);
    node * ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
}

void DeleteAtEnd(node *&head)
{
    node * p = head;
    node * q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete(q);
}

void Display(node *&head)
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
    InsertAtFirst(head, 15);
    InsertAtTail(head, 87);
    InsertAtEnd(head, 21);
    InsertInBetween(head, 96, 1);
    InsertAtTail(head, 56);
    InsertAtEnd(head, 67);
    Display(head);

    cout<<endl<<"After deleting the elements "<<endl;

    DeleteAtFirst(head);
    DeleteAtEnd(head);
    DeleteAtIndex(head, 2);
    Display(head);

    return 0;
}