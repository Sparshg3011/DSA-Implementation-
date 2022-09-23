#include <iostream>
using namespace std;

class queue
{
    int size;
    int front;
    int back;
    int *arr;

public:
    queue()
    {
        size = 1;
        front = -1;
        back = -1;
        arr = new int(size);
    }

    int IsEmpty()
    {
        if (front == -1 || front == back)
        {
            return 1;
        }
        return 0;
    }

    int IsFull()
    {
        if (back == size - 1)
        {
            return 1;
        }
        return 0;
    }

    void push(int val)
    {
        if (IsFull())
        {
            cout << "The queue is full " << endl;
        }
        else
        {
            back++;
            arr[back] = val;
        }
        if (front == -1)
        {
            front++;
        }
    }
    int pop()
    {
        if (IsEmpty())
        {
            cout << "The queue is empty " << endl;
            return -1;
        }
        else
        {
            int a = front;
            front++;
            return a;
        }
    }
    int peek()
    {
        return front;
    }
    void display()
    {
        for(int i = front; i <= back; i++)
        {
            cout<<"Element "<<i<<": "<<arr[i]<<endl;
        }
    }
};

int main()
{
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    cout<<endl<<"After popping elements:"<<endl;
    q.pop();
    q.pop();
    q.display();
    cout<<q.IsFull();

    return 0;
}