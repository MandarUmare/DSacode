#include <iostream>
#define I 32767
using namespace std;

int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                   {2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int included[9] = {0};
int i, j=0, k, u, v,n=7, e = 9;

int t[2][6];

int  find(int u)
{
    int x=u,v=0;
  
    while(set[x]>0)
    {
       x=set[x];
    }
    while (u!=x)
    {
        v=set[u];
        set[u]=x;
        u=v;
    }
    return x;
}

void unionn(int u,int v)
{
    if( set[u]>set[v])
    {
        set[u]+=set[v];
        set[v]=u;
    }
    else
    { 
        set[v]+=set[u];
        set[u]=v;

    }

}

int main()
{
    

    while (j < n - 1)
    {
         int min = I;
        for (i = 0; i < e; i++)
        {
            if (included[i]==0 && edges[2][i] < min)
            {
                min = edges[2][i];
                u = edges[0][i];
                v = edges[1][i];
                k = i;
            }
        }

        if (find(u) != find(v))
        {
           
            t[0][j] = u;
            t[1][j] = v;
            unionn(find(u), find(v));
            j++;
        }

        included[k] = 1;
       
    }



   for (i = 0; i < n-1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }


    return 0;
}