#include<iostream>
using namespace std;

int * fun(int n){
    int *P=new int[n];
    for (int i = 0; i < n; i++)
    {
       cin>>P[i];
    }
    return P;
}


int main(){
    int *A;
    A=fun(5);
    for (int i = 0; i < 5; i++)
    {
       cout<<A[i];
    }
    
return 0;
}