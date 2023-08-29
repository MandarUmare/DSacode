#include <iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void deletee(node *p, int pos)
{   int x;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    if (pos == 0)
    {
        first = first->next;
        
        x = p->data;
        delete p;
        if (first)
        {
           first->prev = NULL;
        }
        
    }else{
    p->prev->next = p->next;
    if (p->next)
    {
        p->next->prev = p->prev;
    }
    
   
    x = p->data;
    delete p;
    }
}

void create(int A[],int n)
{

    first=new node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for (int i = 1; i < n; i++)
    {
        node *t=new node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
        
    }
    
}

void insert(node *p, int pos, int x)
{
    node *t = new node;
    t->data = x;

    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    if (pos == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        t->next = p->next;
        t->prev = p;
        p->next = t;
        p->next->prev = t;
    }
}
void display(node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

void reverse(node *p)
{   
    p=first;
    while(p!=NULL){
    node *temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;

    if (p->next==NULL )
    {   
        p->next=p->prev;
        p->prev=NULL;
        first=p;
        break;          
        
    }
    
    }

}

int main()
{  int A[]={1,2,3,4,5,6};

    create(A,6);
   
    // insert(first, 0, 4);
    // deletee(first,5);
    reverse(first);
    display(first);
    
    return 0;
}