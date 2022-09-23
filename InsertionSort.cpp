#include<iostream>
using namespace std;

void Display(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void InsertArray(int *arr, int n)
{
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

void InsertionSort(int *arr, int n)
{
    int j;
    for(int i = 1; i <= (n-1); i++)
    {
        int key = arr[i];
        j = i-1;
        while(arr[j] > key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n = 7;
    int arr[n];
    
    InsertArray(arr, n);
    Display(arr, n);
    InsertionSort(arr, n);
    cout<<endl<<"After sorting the array "<<endl;
    Display(arr, n);
    
}