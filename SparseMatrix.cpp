#include <iostream>
using namespace std;

struct sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

struct Element
{
    int i;
    int j;
    int x;
};

void create(struct sparse *s, int m, int n, int num)
{
    s->m = m;
    s->n = n;
    s->num = num;
    s->ele = new struct Element[s->num];

    for (int i = 0; i < s->num; i++)
    {
        cout << "enter The elements ";
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
        cout << endl;
    }
}

void display(struct sparse s)
{
    // int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            for (int k = 0; i < s.num; k++)
            {
                if (s.ele[k].i == i && s.ele[k].j == j)
                {
                    cout << s.ele[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
        }
        cout << endl;
    }
}
int main()
{
    struct sparse s;
    cout << "enter the dimensions " << endl;
    cin >> s.m >> s.n >> s.num;
    cout << endl;

    create(&s, s.m, s.n, s.num);
    display(s);

    return 0;
}