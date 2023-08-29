#include <iostream>
using namespace std;

int p[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int fib(int n)
{
    if (n <= 1)
    {
        p[n] = n;
    }
    else
    {
        if (p[n - 1] == -1)
        {
            p[n - 1] = fib(n - 1);
        }
        if (p[n - 2] == -1)
        {
            p[n - 2] = fib(n - 2);
        }

        return p[n - 1] + p[n - 2];
    }
}
int main()
{

    cout << fib(6);
    return 0;
}