#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partitionindex(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    int pivotindex;
    if (low < high)
    {
        pivotindex = partitionindex(arr, low, high);
        quicksort(arr, low, pivotindex - 1);
        quicksort(arr, pivotindex + 1, high);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int arr[n];
    int low = 0;
    int high = n-1;
    cout<<"Enter the elements you want to insert :"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Before sorting "<<endl;
    display(arr, n);
    quicksort(arr, low, high);
    cout<<endl<<"After sorting "<<endl;
    display(arr, n);
    return 0;
}

