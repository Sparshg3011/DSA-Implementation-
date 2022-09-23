#include<iostream>
using namespace std;

class queue
{
    public:
    int front;
    int rear;
    int size;
    int *arr;
    queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int(size);
    }
    void EnqueueFront(int val)
    {
        if(front == 0)
        {
            cout<<"The queue is full from front "<<endl;
        }
        else if(front == -1)
        {
            rear = front = 0;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front]  = val;
        }
    }
     void EnqueueRear(int val)
    {
        if(rear == (size - 1))
        {
            cout<<"The queue is full from rear "<<endl;
        }
        else if(rear == -1)
        {
            rear = front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear]  = val;
        }
    }
    int DequeueFront()
    {
        int value = -1;
        if(front == -1 && rear == -1)
        {
            cout<<"The  queue is full from front"<<endl;
            return value;
        }
        else if(rear == 0)
        {
            value = arr[front];
            front = rear = -1;
            front++;
            return value;
        }
        else
        {
            value = arr[front];
            front++;
            return value;
        }
    }
    int DequeueRear()
    {
        int value = -1;
        if(front == -1 && rear == -1)
        {
            cout<<"The  queue is full from rear"<<endl;
            return value;
        }
        else if(rear == 0)
        {
            value = arr[rear];
            front = rear = -1;
            front++;
            return value;
        }
        else
        {
            value = arr[rear];
            rear--;
            return value;
        }
    }
    void Display()
    {
        for(int i = front; i <= rear; i++)
        {
            cout<<"Element "<<i<<": "<<arr[i]<<endl;
        }
    }
};

int main()
{
    queue q(7);
    q.EnqueueRear(15);
    q.EnqueueRear(23);
    q.EnqueueRear(45);
    q.EnqueueRear(98);

    q.Display();

    cout<<"Dequeuing from front "<<endl;

    q.DequeueFront();
    q.DequeueFront();
    q.DequeueFront();

    q.Display();

    cout<<"Enqueuing from front "<<endl;

    q.EnqueueFront(12);
    q.EnqueueFront(56);
    q.EnqueueFront(87);
    
    q.Display();

    return 0;
}
