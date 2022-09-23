#include <iostream>
using namespace std;

class SortArray
{
public:
    int used_size;
    int total_size;
    int *ptr;
    void CreateArray(SortArray *a, int t_size, int u_size)
    {
        a->total_size = t_size;
        a->used_size = u_size;
        a->ptr = new int(t_size);
    }
    void SetArray(SortArray *a)
    {
        for (int i = 0; i < used_size; i++)
        {
            int s;
            cout << "Enter the element " << i + 1 << " of the array: " << endl;
            cin >> s;
            (a->ptr)[i] = s;
        }
    }
    void ShowArray(SortArray *a)
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << "Element " << i << ": " << (a->ptr)[i] << endl;
        }
    }
    int linearsearch(SortArray *a, int element)
    {

        for (int i = 0; i < used_size; i++)
        {
            if ((a->ptr)[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    int binarysearch(SortArray *a, int element)
    {

        int low, mid, high;
        mid = (low + high) / 2;
        low = 0;
        high = used_size - 1;
        while (low <= high)
        {
            if ((a->ptr)[mid] == element)
            {
                return mid;
            }
            if ((a->ptr)[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    SortArray arr;
    arr.CreateArray(&arr, 10, 6);
    arr.SetArray(&arr);
    arr.ShowArray(&arr);
    // int f = arr.binarysearch(&arr, 4);
    // cout<<f;
    int f = arr.binarysearch(&arr, 4);
    cout << f;
    return 0;
}
