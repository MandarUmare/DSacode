#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insert(int *A, int n, int data)
{
    int i, temp;
    i = n;
    temp = data;
   
    while (i > 1 && temp > A[i / 2] )
    {
        if(temp==A[i/2]){
            break;
        }
        A[i] = A[i / 2];
        i = i / 2;
    }

    A[i] = temp;
}

int Delete(int *A, int n, int data)
{
    int i = 1, j, temp;

    int cnt = n;
    while (cnt > 0)
    {
        if (data == A[cnt])
        {
            temp = A[cnt];
            A[cnt] = A[n];
            // A[n]=temp;
        }
        cnt--;
    }

    j = 2 * i;
    while (j < n - 1)
    {

        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
}

int min(int *A,int n)
{
    int i = 1, min =29239;
    for (int i = 1; i < n; i++)
    {
        
        if (A[i] <min)
        {
            min = A[i];
        }
    }
    
    return min;
}
int main()
{
    int x, c, idata, ddata;
    static int n = 1;
    int A[100];
    A[0] = 0;
    cout << "Enter the number of Queries" << endl;
    cin >> x;
    while (x > 0)
    {
        cout << "Enter the choice" << endl;
        cin >> c;
        x--;
        switch (c)
        {
        case 1:
            cin >> idata;
            insert(A, n, idata);
            n++;
            break;
        case 2:
            cin >> ddata;
            Delete(A, n - 1, ddata);
            n--;
            break;
        case 3:
            cout << min(A,n)<<endl;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
