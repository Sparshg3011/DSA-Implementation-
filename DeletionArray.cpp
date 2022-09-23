#include <iostream>
using namespace std;

class Myarray
{
public:
    int used_size;
    int total_size;
    int *ptr;
    void Createarray(Myarray *a, int t_size, int u_size);
    void Setarray(Myarray *a);
    void Showarray(Myarray *a);
    void Insertion(Myarray *a, int element, int index);
    void Deletion(Myarray *a, int index);
};

void Myarray ::Createarray(Myarray *a, int t_size, int u_size)
{
    used_size = u_size;
    total_size = t_size;
    (a->ptr) = new int(total_size);
}

void Myarray ::Setarray(Myarray *a)
{
    int s;
    for (int i = 0; i < used_size; i++)
    {
        cout << "Enter the elememt " << i + 1 << " of the array: " << endl;
        cin >> s;
        (a->ptr)[i] = s;
    }
}

void Myarray ::Showarray(Myarray *a)
{
    cout<<"The array is "<<endl;
    for (int i = 0; i < used_size; i++)
    {
        cout << "Element " << i + 1 << " : " << (a->ptr)[i] << endl;
    }
}

void Myarray ::Insertion(Myarray *a, int element, int index)
{
    for (int i = used_size - 1; i >= index; i--)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }
    (a->ptr)[index] = element;
    used_size ++;
}

void Myarray ::Deletion(Myarray *a, int index)
{
    for (int i = index; i < used_size; i++)
    {
        (a->ptr)[i] = (a->ptr)[i + 1];
    }
    used_size --;
}

int main()
{
    Myarray arr;
    int choice;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter the operation you want to perform on array: " << endl
             << "1.Create Array" << endl
             << "2. Set Array" << endl
             << "3. Show Array" << endl
             << "4. Insertion" << endl
             << "5. Deletion" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int t, u;
            cout << "Enter the Capacity of the array: " << endl;
            cin >> t;
            cout << "Enter the used size of the array: " << endl;
            cin >> u;
            arr.Createarray(&arr, t, u);
        }
        break;

        case 2:
        {
            arr.Setarray(&arr);
            arr.Showarray(&arr);
        }

        case 3:
        {
            arr.Showarray(&arr);
        }
        break;

        case 4:
        {
            int element, index_insert;
            cout << "Enter the element you want to insert: " << endl;
            cin >> element;
            cout << "Enter the index value where you want to insert: " << endl;
            cin >> index_insert;

            arr.Insertion(&arr, element, index_insert);
            arr.Showarray(&arr);
        }
        break;

        case 5:
        {
            int index_del;
            cout << "Enter the element you want to delete :" << endl;
            cin >> index_del;

            arr.Deletion(&arr, index_del);
            arr.Showarray(&arr);
        }
        break;

        default:
        {
            cout << "Invalid choice";
        }
        }
        cout << "Woul you like to continue(Y/y): " << endl;
        cin >> ch;
    }
   
}
