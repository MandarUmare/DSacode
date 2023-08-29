#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int *temp = x;
    x = y;
    y = temp;
}


int partition(int *A,int l,int h)
{
    int pivot,i,j;
    pivot=A[l];
    i=l;
    j=h;
    do
    {
      do{i++;} while (A[i]<=pivot);
      do{j--;} while (A[j]>pivot);
      if(i<j){
        swap(A[i],A[j]);
      }
    } while (i<j);
    swap(A[l],A[j]);
    return j;
}
void quicksort(int *A, int l,int h)
{
  int j;
    if(l<h)
    {
        j=partition(A,l,h);
        quicksort(A,l,j);
        quicksort(A,j+1,h);

    }
    
    
}
int main()
{
    int A[] = {6, 3, 8, 1, 9, 3, 0, 6,10};
    quicksort(A,0,9);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}