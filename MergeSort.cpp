#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int k = low;
    int j = mid + 1;
    int B[50];
    // int * B = new int(high - low + 1);

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            B[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        k++;
        j++;
    }
    for (int l = low; l <= high; l++)
    {
        arr[l] = B[l]; 
    }
}

void mergesort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int n;
    int low = 0;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    int high = n - 1;
    int arr[n];
    cout<<"Enter the elements of the array :"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    display(arr, n);
    cout<<endl<<"After sorting "<<endl;
    mergesort(arr, low, high);
    display(arr, n);
}