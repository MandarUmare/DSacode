#include <iostream>
using namespace std;

int *merge(int *a, int m, int *b, int n)
{
    int *c = new int[10];
    int i = 0, j = 0, k = 0;
    while (k<10)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }

        else
        {
            c[k++] = b[j++];
        }
    }
    for (; i < m; i++)
    {
        c[k++] = a[i];
    }
    for (; j < m; j++)
    {
        c[k++] = a[j];
    }
    return c;
}
int main()
{

    int A[5] = {1, 6, 3, 7, 5};
    int B[5] = {2, 4, 8, 9, 10};

    int *p;
    p = merge(A, 5, B, 5);
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << endl;
    }

    return 0;
}