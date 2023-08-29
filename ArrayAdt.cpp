#include <iostream>
#include <stdio.h>
using namespace std;

struct Array
{
    int *A;
    int length;
    int size;
};

int BinSearch(struct Array r, int key)
{
    int mid, l, h;
    l = 0;
    h = r.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == r.A[mid])
            return mid;

        if (key < r.A[mid])
            h = mid - 1;

        else
            l = mid + 1;
    }
    return -1;
}

int RbinSearch(struct Array r, int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == r.A[mid])
            return mid;
        if (key < r.A[mid])
            return RbinSearch(r, l, mid - 1, key);
        else
            return RbinSearch(r, mid + 1, h, key);
    }
    return -1;
}
int search(struct Array r, int key)
{
    for (int i = 0; i < r.length; i++)
    {
        if (r.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int delet(struct Array *r, int index)
{
    if (index >= 0 && index < r->length)
    {
        int x = r->A[index];
        for (int i = index; i < r->length - 1; i++)
        {
            r->A[i] = r->A[i + 1];
        }
        r->length--;
        return x;
    }
   
}
void insert(struct Array *r, int index, int x)
{
    if (index >= 0 && index <= r->length)
    {
        for (int i = r->length; i > index; i--)
        {
            r->A[i] = r->A[i - 1];
        }
        r->A[index] = x;
        r->length++;
        return;
    }
}

void display(struct Array r)
{
    for (int i = 0; i < r.length; i++)
    {
        cout << r.A[i] << endl;
    }
}
int main()
{
    int index;

    int x;
    struct Array r;
    r.length = 0;
    cout << "Enter the size of an array" << endl;
    cin >> r.size;

    r.A = new int[r.size];
    int n;
    do
    {

        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Search" << endl;
        cout << "5. BinSearch" << endl;
        cin >> n;

        switch (n)
        {
        case 1:

            cout << "Enter the index" << endl;
            cin >> index;
            cout << "Enter the element" << endl;
            cin >> x;
            insert(&r, index, x);
            break;

        case 2:

            display(r);
            break;
        
        case 3:
          cout<<"Enter the Index you want to delete"<<endl;
          cin>>index;
           cout<<"Sucessfully deleted the element"<< delet(&r,index);
          break;

         case 4:
          cout<<"Enter the element you want to Search"<<endl;
          cin>>x;
          cout<<"the element is at index :"<<search(r,x);
          break;

         case 5:
          cout<<"Enter the element you want to BinSearch"<<endl;
          cin>>x;
          cout<<"the element is at index :"<<BinSearch(r,x);
          break;
        }

    } while (n < 6);

    return 0;
}