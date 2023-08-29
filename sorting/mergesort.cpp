#include <iostream>
#include <math.h>
using namespace std;

void swap(int *x, int *y)
{
    int *temp = x;
    x = y;
    y = temp;
}

void merge(int *A, int l, int mid, int h)
{
    int i, j, k = l;
    int B[100];

    i = l, j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j <= h; j++)
    {
        B[k++] = A[j];
    }
    for (int i = 0; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int *A, int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = floor((l + h) / 2);
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void imergesort(int *A, int n)
{
    int  p,l, mid, h, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = floor((l + h) / 2);
            merge(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}
int main()
{
    int A[] = {5, 7, 2, 4, 9,8, 10, 1, 3, 6};
    imergesort(A, 10);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}