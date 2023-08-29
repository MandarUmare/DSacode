#include <iostream>
#include <math.h>
using namespace std;

void swap(int *x, int *y)
{
    int *temp = x;
    x = y;
    y = temp;
}

void shellsort(int *A, int n)
{
    int gap;
    int j, i,temp;

    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {

         
        for (i = gap; i < n; i++)
        {

           
            
            j = i - gap;
            temp = A[i];
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {6, 3, 8, 1, 9, 3, 0, 6, 10};
    shellsort(A, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}