#include <iostream>
using namespace std;

void insert(int *A, int n)
{
    int i, temp;
    i = n;
    temp = A[n];

    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }

    A[i] = temp;
}



int Delete(int *A, int n)
{
    int i=1,j,temp;
    temp=A[1];
    A[1] = A[n];
    A[n]=temp;
 
  j=2*i;
 while(j<n-1)
{    
     
    
    if(A[j+1]>A[j])
    {
       j=j+1;
    }
    if(A[i]<A[j]){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i=j;
        j=2*j;
    }
    else{
        break;
    }
}

return temp;
}

int main()
{
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    for (int i = 2; i <= 7; i++)
    {
        insert(A, i);
    }
    for (int i = 7; i >1; i--)
    {
       Delete(A, i);
    }
    for (int i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}