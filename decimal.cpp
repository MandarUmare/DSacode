#include <iostream>
using namespace std;



int Binary(int Dec,int *p){
    int static length=0;
    for(int i=0;Dec>0;i++){
        p[i]=Dec%2;
        Dec=Dec/2;
        length++;
    }
    return length;
    
    
}
int main(){
    int Dec;
    int a[10];
    int l;
    cout<<"Enter the Decimal No:";
    cin>>Dec;
  
    l=Binary(Dec,a);
    cout<<l;
    for (int i = l; i>0; i--)
    {
        cout<<a[i];
    }
    
    
}