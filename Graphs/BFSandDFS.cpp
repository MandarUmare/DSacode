#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

} *Front = NULL, *Rear = NULL;

void enqueue(int x)
{
    struct node *t = new node;

    if (t == NULL)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (Front == NULL)
        {
            Front = Rear = t;
        }
        else
        {
            Rear->next = t;
            Rear = t;
        }
    }
}

int dequeue()
{
    struct node *p;
    int x;
    if (Front == NULL)
    {
        cout << "the queue is empty" << endl;
    }
    else
    {
        x = Front->data;
        p = Front;
        Front = Front->next;
        delete p;
    }
    return x;
}

int isempty()
{
    if (Front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    struct node *p = Front;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

void BFS(int A[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};
    cout << i << " ";

    visited[i] = 1;
    enqueue(i);
    while (!isempty())
    {
        i = dequeue();
        for (int j = 1; j < n; j++)
        {
            if (A[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
    cout<<endl;
}

void DFS(int A[][7], int start, int n)
{
     int i=start;
    static int visited[7]={0};
    if(visited[i]==0)
    {
        cout<<i<<" ";
        visited[i]=1;
       for (int j = 1; j < n; j++)
       {
         if(A[i][j]==1 && visited[j]==0)
         {
           
            DFS(A,j,n);
         }
       }
       
    }
}
int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 1, 7);
    DFS(G, 1, 7);
    return 0;
}