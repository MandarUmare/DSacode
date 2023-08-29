#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void perm(char *S, int l, int h)
{
    int i;
    if (l == h)
    {
       printf("%s ", S);
    }
    else
    {
        for (i = l; S[i] != '\0'; i++)
        {
            swap(S[l], S[i]);
            perm(S,l+1,h);
            swap(S[l], S[i]);
        }
    }
}
int main()
{
    char str[]="ABC";

  

    perm(str,0,2);
    return 0;
}