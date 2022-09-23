#include <iostream>
using namespace std;

class myarray
{
public:
    int total_size;
    int used_size;
    int *ptr;
    void createarray(myarray *a, int t_size, int u_size);
    void setarray(myarray *a);
    void showarray(myarray *a);
    void insertion(myarray *a, int element, int index);
};

void myarray ::createarray(myarray *a, int t_size, int u_size)
{
    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = new int(t_size);
}

void myarray ::setarray(myarray *a)
{
    int val;
    for (int i = 0; i < used_size; i++)
    {
        cout << "Enter the " << i + 1 << " element in the array: " << endl;
        cin >> val;
        (a->ptr)[i] = val;
    }
}

void myarray ::showarray(myarray *a)
{
    for (int i = 0; i < used_size; i++)
    {
        cout << "Element " << i + 1 << ": " << (a->ptr)[i] << endl;
    }
}

void myarray ::insertion(myarray *a, int element, int index)
{
    for (int i = used_size; i >= index; i--)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }
    (a->ptr)[index] = element;
}

int main()
{
    myarray array;
    array.createarray(&array, 10, 6);
    array.setarray(&array);
    array.showarray(&array);

    cout << "Array after insertion of an element is: " << endl;
    array.insertion(&array, 100, 2);
    array.used_size += 1;
    array.showarray(&array);

    return 0;
}
