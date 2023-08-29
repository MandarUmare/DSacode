#include <iostream>
using namespace std;

struct node
{
    node *lchild;
    int height;
    int data;
    node *rchild;

} *root = NULL;


int height(node *p)
{

    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    
   return hl>hr?hl+1:hr+1;
}

int balancefactor(node *p)
{
     int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;
}

node * LLRotation(node *p){
     node *pl=p->lchild;
     node *plr=pl->rchild;
    pl->rchild=p;
     p->lchild=plr;
     p->height=height(p);
     pl->height=height(p);
    if(root==p)
    {
       root=pl;
    }
    return pl;
}
node *insert(struct node *p, int data)
{

    node *t=NULL;
    if(p==NULL)
    {   
        t=new node;
        t->data=data;
        t->lchild=t->rchild=NULL;
        t->height=1;
        
        return t;
    }
    
    if (data < p->data)
    {
        p->lchild = insert(p->lchild, data);
    }
     if (data > p->data)
    {
        p->rchild = insert(p->rchild, data);
    }
    p->height=height(p);
    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
    {
        return LLRotation(p);
    }
    // else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
    // {
    //     return LRRotation(p);
    // }
    // else if(balancefactor(p)==-2 && balancefactor(p->lchild)==-1)
    // {
    //     return RRRotation(p);
    // }
    // else if(balancefactor(p)==-2 && balancefactor(p->lchild)==1)
    // {
    //     return RLRotation(p);
    // }
    return p;
}

void inorder(struct node *p)
{

    if(p){
        cout<<p->data<<" ";
        inorder(p->lchild);
      
        inorder(p->rchild);
    }
}

int main()
{
     root=insert(root,5);
    insert(root,4);
    insert(root,3);
    inorder(root);
    return 0;
}