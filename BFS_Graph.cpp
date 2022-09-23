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
        size = 10;
        front = 0;
        back = 0;
        arr = new int(size);
    }

    int IsEmpty()
    {
        if (front == back)
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
    
    }
    int pop()
    {
        int a = -1;
        if (IsEmpty())
        {
            cout << "The queue is empty " << endl;
            return -1;
        }
        else
        {
            front++;
            a = arr[front];
            return a;
        }
    }
    int peek()
    {
        return front;
    }
    void display()
    {
        for (int i = front; i <= back; i++)
        {
            cout << "Element " << i << ": " << arr[i] << endl;
        }
    }
};

int main()
{
    queue q;
    int node;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int i = 4;
    int a[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    cout << i << " ";
    visited[i] = 1;
    q.push(i);
    while (!q.IsEmpty())
    {
        node = q.pop();
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return 0;
}