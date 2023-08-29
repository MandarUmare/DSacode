#include <iostream>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

void insert(int key)
{
    struct node *r = NULL, *p,*t=root;
    if (root== NULL)
    {
        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }else if(key>t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }

        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
       
    if(key>r->data){
        r->rchild=p;
    }else{
        r->lchild=p;
    }

}

node * search(int key)
{  
    node *t=root;

    while (t!=NULL)
    {
      
  
    
    if(root==NULL){
        return NULL;
    }
    else if(key>t->data){
        t=t->rchild;
    }
    else if(key<t->data){
        t=t->lchild;
    }
    else{
        return t;
    }
    }
    return NULL;
}

void inorder(struct node *p)
{

    if(p){
      
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

int main()
{  

   
    insert(12);
    insert(16);
    insert(14);
    insert(20);
    insert(15);
    insert(10);
    insert(8);
    insert(9);
    insert(11);
    insert(5);
    insert(6);
    insert(7);
    inorder(root);
    node *t=search(5);
    if(t!=NULL){
        cout<<endl<<"the key "<<t->data<<" found"<<endl;
    }
    else{
        cout<<"Key does not found"<<endl;
    }
    return 0;
}