#include <iostream>
using namespace std;

class circularqueue
{
public:
    int front;
    int rear;
    int size;
    int *arr;
    circularqueue()
    {
        front = rear = 0;
        size = 5;
        arr = new int(size);
    }

    int IsEmpty()
    {
        if ((front) == (rear))
        {
            return 1;
        }
        return 0;
    }

    int IsFull()
    {
        if ((rear + 1) % size == front)
        {
            return 1;
        }
        return 0;
    }

    void Enqueue(int val)
    {
        if (IsFull())
        {
            cout << "The queue is full" << endl;
        }
        else
        {
            cout << "Enqueued element is : " << val << endl;
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
    }

    int Dequeue()
    {
        int value = -1;
        if (IsEmpty())
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            front = (front + 1) % size;
            value = arr[front];
            cout << "Dequeuing element " << value << endl;
        }
        return value;
    }

    void Display()
    {
        int j = 0;
        int i = 0;
        if (rear >= front)
        {
            for (i = front + 1; i <= rear; i++)
            {
                cout << "Element " << j << ": " << arr[i] << endl;
                j++;
            }
        }
        else
        {
            for (i = front + 1; i < size; i++)
            {
                cout << "Element " << j << ": " << arr[i] << endl;
                j++;
            }
            for (i = 0; i <= rear; i++)
            {
                cout << "Element " << j << ": " << arr[i] << endl;
                j++;
            }
        }
    }
};
int main()
{
    circularqueue q;

    q.Enqueue(12);
    q.Enqueue(34);
    q.Enqueue(56);
    q.Enqueue(90);
    q.Enqueue(78);
    q.Display();
    q.Dequeue();
    q.Dequeue();
    q.Display();
    q.Enqueue(23);
    q.Enqueue(21);

    q.Display();
    return 0;
}