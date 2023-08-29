#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    
    
}*Front=NULL,*Rear=NULL;



void enqueue(int x)
{
    struct node *t=new node;
   
    if(t==NULL)
    {
        cout<<"Queue is full"<<endl;
    }
    else{
         t->data=x;
          t->next=NULL;
        if(Front==NULL ){
            Front=Rear=t;
           
        }else{
            Rear->next=t;
            Rear=t;
        }
    }
}

int dequeue()
{
    struct node *p;
    
    
    if(Front==Rear)
    {
        cout<<"the queue is empty"<<endl;
    }
    else{
        p=Front;
        Front=Front->next;
        delete p;

    }
    return p->data;

}

void display()
{
    struct node *p=Front;
    while (p!=NULL)
    {
       cout<<p->data<<endl;
       p=p->next;
    }
    
}
int main()
{
    enqueue( 10);
    enqueue( 30);
    enqueue( 40);
    enqueue( 50);
    dequeue();
    display();
return 0;
}