#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int *temp = x;
    x = y;
    y = temp;
}

void bubble(int *A, int n)
{
    int flag;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                flag = 0;
                swap(A[j], A[j + 1]);
            }
        }

        if (flag !=0 )

            break;
    }
}
int main()
{
    int A[] = {6, 3, 8, 1, 9, 3, 0, 6};
    bubble(A, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}