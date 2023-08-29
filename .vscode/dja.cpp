#include<iostream>
using namespace std;

int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
       result_count=&arr_count;
         int i=0;
         while( i<d) {
         int x,j;
         x=arr[arr_count-1];
         for ( j=0; j<arr_count;j++) {
           arr[j]=arr[j+1];
          }
         arr[j]=x;
         i++;
       }
       return arr;
}
int main()
{   int b[10];
    int a[5]={1,2,3,4,5};
    
    int *p=rotateLeft(3,5,a,b);
    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<" ";
    }
    
return 0;
}