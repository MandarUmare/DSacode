#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int *temp = x;
    x = y;
    y = temp;
}

void selectionsort(int *A, int n)
{

    int k;
    for (int i = 0; i <n; i++)
    {
       for (int j=k=i; j <n; j++)
       {
        if(A[j]<A[k])
        {
            k=j;
        }
       }

       swap(A[i],A[k]);
       
    }
    
}
int main()
{
    int A[] = {6, 3, 8, 1, 9, 3, 0, 6};
    selectionsort(A, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}