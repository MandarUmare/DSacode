#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

} *top = NULL;

void push(int x)
{
    node *t = new node;
    if (t == NULL)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

void pop()
{
    node *p = new node;
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        p = top;
        top = top->next;
        delete p;
    }
}

int peek(int pos)
{
    node *p=new node;
    p=top;
    for (int i = 0;p!=NULL && i < pos-1; i++)
    {
        p=p->next;
    }
    if(p)
    {
        return p->data;
    }
    else{
        return -1;
    }
    
}

int isFull()
{
    node *t=new node;
   int r=t?1:0;
   delete t;
   return r;
}

int isEmpty(){
    return top?0:1;
}
void display()
{
    node *p = new node;
    p = top;
    while (p != NULL)
    {   
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    pop();
    cout<<peek(2)<<endl;
    display();


    return 0;
}