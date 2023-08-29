

#include <bits/stdc++.h>
using namespace std;

int f[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int countDistinctWays(int nStairs) {
   
   if(nStairs==0){
       f[nStairs]=1;
       return 1;
   }
   else{
       if(f[nStairs-2]==-1){
           f[nStairs-2]=countDistinctWays(nStairs-2) ;
       }
       if(f[nStairs-1]==-1){
           f[nStairs-1]=countDistinctWays(nStairs-1) ;
       }
       return f[nStairs-2]+f[nStairs-1];
    }
}
int main()
{

    cout << countDistinctWays(8);
    return 0;
}