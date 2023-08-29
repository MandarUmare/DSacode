#include<iostream>
using namespace std;

void print(int a[],int size){
  
    for (int  i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    
}
int main(){

int a[]={2,4,4,4,5};

print(a,5);


return 0;
}