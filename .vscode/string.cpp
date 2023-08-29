#include <iostream>
#include <string.h>
using namespace std;

char *str2(char *s1, char *s2)
{
    int i = 0, j = 0, k = 0;
    char *array = new char[20];
    int x;
    static int flag=-1;
    while (s1[i]!='\0')
    {

        if (s1[i] == s2[j] )
        {    x=i;

            while (s1[i] == s2[j] || s1[i]!='\0')
            {
                array[k++] = s1[i++];
                j++;
            }
        }
      
        i++;
    }
    

    return array;
}

int main()
{

    char s1[20];
    char s2[10];

    cout << "Enter string " << endl;
    cin.getline(s1, 20);

    cout << "Enter string " << endl;
    cin.getline(s2, 10);

    char *s;
    s = str2(s1, s2);
    cout << s;

    return 0;
}