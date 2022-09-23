#include <iostream>
using namespace std;

void InsertionArray(int *arr, int n)
{
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int *arr, int n)
{
    int IndexofMin;
    int i;
    for (i = 0; i < (n - 1); i++)
    {
        IndexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[IndexofMin])
            {
                IndexofMin = j;
            }
        }
        swap(arr[i], arr[IndexofMin]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array :" << endl;
    cin >> n;

    int arr[n];

    InsertionArray(arr, n);
    Display(arr, n);
    SelectionSort(arr, n);
    cout << endl
         << "After sorting the array " << endl;
    Display(arr, n);

    return 0;
}