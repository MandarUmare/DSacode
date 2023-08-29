#include <iostream>
using namespace std;

void swap(int *x,int *y)
{
    int *temp=x;
    x=y;
    y=temp;
}

void insertsort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {   
         int x;
         int j=i-1;
         x=A[i];
         
         while (j>-1 && A[j]>x)
         {
            A[j+1]=A[j];
          
            j--;
         }
         A[j+1]=x;
    } 
}
int main()
{
    int A[] = {6, 3, 8, 1, 9, 3, 0, 5};
    insertsort(A, 8);
    for (int i = 0; i < 8; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}