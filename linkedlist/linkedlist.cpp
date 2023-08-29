#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first =NULL, *last =NULL;

void insertSorted(node *p,int x){
    node *q=NULL;
    while(p!=NULL)
    {
        if(p->data<x){
        q=p;
        p=p->next;
        }
        else{
            node *t=new node;
            t->data=x;
            t->next=p;
            q->next=t;
        }


    }
}

int deletee(node *p, int pos)
{
    node *q = NULL;
    int x;

    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next=p->next;
    x=p->data;
    delete p;
    return x;

}
int isSorted(node *p)
{

    int x = -32768;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        else
        {
            x = p->data;
        }

        p = p->next;
    }
    return 1;
}

void removeduplicate(node *p)
{
    node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int max(struct node *p)
{
    int max = -30000;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }

        p = p->next;
    }
    return max;
}

node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }

        p = p->next;
    }
    return NULL;
}

// int rmax(struct node *p){

//    if(p==NULL){
//       return max;
//     }
//     else{
//         if(p->data>max){
//             max=p->data;

//         }
//         return rmax(p->next);

//     }
//    }

int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct node *p, int pos, int x)
{
    if (pos < 0)
    {
        return;
    }
    else
    {   for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

       
        if (pos == 0)
        {
            struct node *t = new node;
            t->data = x;
            t->next = first;
            first = t;
        }
        
        else
        {
            struct node *t = new node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void reverse(struct node *p)
{
    node *q = NULL;
    node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void create(int x)
{
    struct node *t = new node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{

    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    create(5);
    create(6);
    create(6);
    create(6);
    create(6);
    create(7);
    create(7);
    create(8);
    insert(first, 0, 1);
    insertSorted(first,5);
    deletee(first,2);
    
    // reverse(first);
    // removeduplicate(first);
    
    display(first);
    cout << isSorted(first);
    // cout << count(first);
    // if(node *x=search(first,5)){
    //     cout<<"found"<<x->data;
    // }
    // else{
    //     cout<<"not found";
    // }

    // cout<<"The maximum number is"<<rmax(first);
    return 0;
}