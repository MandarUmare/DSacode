#include <iostream>
#include <math.h>
using namespace std;

void swap(int *x, int *y)
{
    int *temp = x;
    x = y;
    y = temp;
}
int findmax(int *A, int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void countsort(int *A, int n)
{
    int size = findmax(A, n);
    int *c = new int[size];
    for (int i = 0; i <size; i++)
    {
        c[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        c[A[i]]++;
    }
    int i = 0;
    int j = 0;
    while (i < size + 1)
    {
        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int A[] = {5, 7, 2, 4, 9, 8, 10, 1, 3, 6};
    countsort(A, 10);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}