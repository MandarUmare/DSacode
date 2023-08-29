#include<iostream>
#include<queue>
using namespace std;


struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;


void create(){
struct node *p,*t;
   queue <node *> q;
   int x;
   cout<<"Enter the root node data "<<endl;
   cin>>x;
   root=new node;
   root->data=x;
   root->lchild=root->rchild=NULL;
   q.emplace(root);

   while(!q.empty())
   {
    p=q.front();
    q.pop();
    cout<<"Enter the lchild of the "<<p->data<<" "<<endl;
    cin>>x;
    if(x!=-1){
    t=new node;
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->lchild=t;
    q.emplace(t);
    }
    cout<<"Enter the rchild of the "<<p->data<<" "<<endl;
    cin>>x;
    if(x!=-1){
    t=new node;
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->rchild=t;
    q.emplace(t);
    }
   }

}


void preorder(struct node *p)
{

    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{

create();
preorder(root);

return 0;
}