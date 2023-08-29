#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first=NULL, *last =NULL;

void create(int A[])
{   
    first=new node;
    first->data = A[0];
    first->next = first;
    last = first;

    for (int i = 1; i < 7; i++)
    {
        node *t = new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(node *p){
    do
    {   
        cout<<p->data<<endl;
        p=p->next;
    } while (p!=first);

   
    
    
}



int main()
{
    int A[] = {1,2,3,4,5,6,7};
    create(A);
    display(first);
               

    return 0;
}