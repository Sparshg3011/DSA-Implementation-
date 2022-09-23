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
void InsertAtHead(node *&head, int val)
{
    node * n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node * ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = head;
    head = n;
}
void InsertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }
    node * n = new node(val);
    node * ptr = head;

    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = head;

}

void InsertInBetween(node *head, int val, int index)
{
    node * n = new node(val);
    node * ptr = head;
    int i = 0;
    while(i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    n->next = ptr->next;
    ptr->next = n;
}

void DeleteHead(node *&head)
{
    node * p = head;
    while(p->next != head)
    {
        p = p->next;
    }
    node * q = head;
    p->next = q->next;
    head = q->next;
    delete q;
}

void Deletion(node *&head, int pos)
{
    if(pos == 1)
    {
        DeleteHead(head);
        return;
    }
    node * p = head;
    node * q = head->next;
    int count = 1;
    while(count != pos-1)
    {
        p = p->next;
        q = q->next;
        count++;
    }
    p->next = q->next;
    delete q;
}

void display(node *&head)
{
    node * ptr = head;
    do
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    } while (ptr != head);
    cout<<"NULL";
    
}

int main()
{
    node * head = NULL;
    InsertAtTail(head, 11);
    InsertAtTail(head, 12);
    InsertAtTail(head, 13);
    InsertAtTail(head, 14);
    InsertAtTail(head, 15);
    InsertAtTail(head, 16);
    InsertAtTail(head, 17);
    InsertAtTail(head, 18);
    InsertAtTail(head, 19);
    InsertAtTail(head, 20);
    display(head);
    cout<<endl<<"After deletion"<<endl;
    Deletion(head, 1);
    display(head);

    return 0;
    
}