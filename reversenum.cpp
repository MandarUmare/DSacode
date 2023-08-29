#include <bits/stdc++.h>
using namespace std;
 void tow(int n,int A,int B,int C){

    if(n>0){
      tow( n-1,A,C,B);
      cout<<"From"<<A<<"to"<<C<<"\n";
      tow(n-1,B,A,C);
    }else{
        return ;
    }
 }
int main()
{
  tow(3,1,2,3);
return 0;
}