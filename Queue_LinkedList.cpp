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

class queue
{
public:
    node *front;
    node *rear;
    queue()
    {
        front = rear = NULL;
    }
    void Enqueue(int val)
    {
        node *ptr = new node(val);
        if (ptr == NULL)
        {
            cout << "The queue is full " << endl;
        }
        else if (front == NULL)
        {
            front = rear = ptr;
            cout<<"Enqueued element is : "<<ptr->data<<endl;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            cout<<"Enqueued element is : "<<ptr->data<<endl;
        }
    }
    bool IsEmpty()
    {
        if(front == NULL)
        {
            return true;
        }
        return false;
    }
    int Dequeue()
    {
        int value = -1;
        if (IsEmpty())
        {
            cout<<"The queue is empty "<<endl;
        }
        else
        {
            node * ptr = front;
            value = ptr->data;
            front = front->next;
            delete ptr;
        }
        return value;
    }
    void Display()
    {
        node * ptr = front;
        int i = 0;
        while(ptr != NULL)
        {
            cout<<"Element "<<i<<": "<<ptr->data<<endl;
            ptr = ptr->next;
            i++;
        }
    }
    int peek()
    {
        return front->data;
    }
};

int main()
{
    queue q;
    q.Enqueue(23);
    q.Enqueue(68);
    q.Enqueue(12);
    q.Enqueue(78);
    
    q.Display();

    return 0;
}