#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;
    node * prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void InsertAtHead(node *&head, int val)
{
    node * n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}
void InsertAtTail(node *&head, int val)
{
    node * n = new node(val);
    if (head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }
    node * ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = NULL;
    n->prev = ptr;
}
void DeleteAtHead(node *&head)
{
    node * ptr = head;
    head = head->next;
    delete ptr;
}
void Deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        DeleteAtHead(head);
        return;
    }
    node * p = head;
    node * q = head->next;
    int count = 0;
    while(count != pos-1 && p != NULL)
    {
        p = p->next;
        q = q->next;
        count++;
    }
    p->next = q->next;
    if (p != NULL)
    {
        q->next->prev = p;
    }
    delete q;
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
    InsertAtHead(head, 23);
    InsertAtTail(head, 45);
    InsertAtTail(head, 23);
    InsertAtTail(head, 78);
    Display(head);

    cout<<endl<<"After inserting at head: "<<endl;
    InsertAtHead(head, 54);
    Display(head);

    cout<<endl<<"After Deleting: "<<endl;
    Deletion(head, 2);
    Display(head);

    return 0;
}