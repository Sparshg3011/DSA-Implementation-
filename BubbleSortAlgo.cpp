#include <iostream>
using namespace std;

void Display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Bubblesortadaptive(int *a, int n)
{
    int isSorted = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        cout<<"Pass number "<<i+1<<endl;
        isSorted = 1;
        for (int j = 0; j < (n -1-i); j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int n = 5;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Display(arr, n);
    Bubblesortadaptive(arr, n);
    Display(arr, n);

    return 0;
}