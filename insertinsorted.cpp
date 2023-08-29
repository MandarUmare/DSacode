#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};

void insert(struct Array *p,int index,int x)
{

    for (int i =  p->length; i <0; i++)
    {
        p->A[i]=p->A[i+1];
    }
    p->A[index]=x;
    p->length++;
    
    
};

void display(struct Array r){
    for (int i = 0; i < r.length; i++)
    {
        cout<<r.A[i]<<endl;
    }
    
}

int isSorted(struct Array r){
    for (int  i = 0; i < r.length-1; i++)
    {
        if(r.A[i]>r.A[i+1]){
            return false;
        }
       
    }
    return true;
    
}

int main(){

    struct Array r={{1,2,3,7,4,5,6},6,10};
   

    // insert(&r,2,7);
    display(r);
    cout<<isSorted(r);
    
return 0;
}