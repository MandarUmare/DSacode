#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    return fib(n-1)+fib(n-2);
}
int main()
{  
  int a;
  int i=0;
  cout<<"Enter the count:";
  cin>>a;
  while(i<=a){
    cout<<"Sequence is "<<fib(i);
    i++;
  }
    return 0;
}