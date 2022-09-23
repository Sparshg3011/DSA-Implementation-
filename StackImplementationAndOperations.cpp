#include <iostream>
using namespace std;

class stack
{
public:
    int top;
    int *arr;
    int size;
    stack()
    {
        size = 100;
        arr = new int(size);
        top = -1;
    }

    int IsEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    int IsFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        return 0;
    }
    void push(int val)
    {
        if (IsFull())
        {
            cout << "Stack overflow" << endl;
        }
        top++;
        arr[top] = val;
    }
    int pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }
    int peek(int pos)
    {
        int index = top - pos + 1;
        if (index < 0)
        {
            cout << "Invalid Position" << endl;
        }
        else
        {
            return index;
        }
    }
    int StackTop()
    {
        return arr[top];
    }
    int StackBottom()
    {
        return arr[0];
    }
    void Display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << "Element " << i << " is " << arr[i] << endl;
        }
    }
};
int main()
{
    stack sp;
    sp.push(30);
    sp.push(35);
    sp.push(40);
    sp.push(45);
    sp.push(50);
    sp.Display();

    cout << endl
         << "Array after deletion" << endl;
    sp.pop();
    sp.pop();
    sp.Display();

    int f = sp.peek(1);
    cout
}