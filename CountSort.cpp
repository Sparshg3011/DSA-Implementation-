#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int maxnumber(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[], int n)
{
    int i, j;
    int count;
    int max = maxnumber(arr, n);
    int k = max + 1;
    int * B = new int(k);
    for (i = 0; i < k; i++)
    {
        B[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        B[arr[i]]++;
    }

    i = 0;
    j = 0;
    while (i <= max)
    {
        if (B[i] > 0)
        {
            arr[j] = i;
            B[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    delete B;
}

int main()
{
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<maxnumber(arr, n);
    cout << "Before sorting " << endl;
    display(arr, n);
    cout << endl
         << "After sorting " << endl;
    countsort(arr, n);
    display(arr, n);
}