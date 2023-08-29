#include <iostream>
#include<stack>
#include<queue>
using namespace std;



struct node
{
   struct  node *lchild;
   int data;
   struct node *rchild;
} *root = NULL;


struct Queue
{
   int size;
   int front;
   int rear;
   struct node **Q;
};
void create(struct Queue *q, int size)
{
   q->size = size;
   q->front = q->rear = 0;
   q->Q = new node*[q->size];
}
void enqueue(struct Queue *q,struct node *x)
{
   if ((q->rear + 1) % q->size == q->front)
      printf("Queue is Full");
   else
   {
      q->rear = (q->rear + 1) % q->size;
      q->Q[q->rear] = x;
   }
}
struct node *dequeue(struct Queue *q)
{
  struct node *x = NULL;

   if (q->front == q->rear)
      printf("Queue is Empty\n");
   else
   {
      q->front = (q->front + 1) % q->size;
      x = q->Q[q->front];
   }
   return x;
}
void Display(struct Queue q)
{
   int i = q.front + 1;

   do
   {

      printf("%d ", q.Q[i]);
      i = (i + 1) % q.size;
   } while (i != (q.rear + 1) % q.size);

   printf("\n");
}
int isEmpty(struct Queue q)
{
   return q.front==q.rear;
}

void treeCreate()
{
   struct node *p, *t;
   struct Queue q;
  
   int x;
    create(&q,100);
   cout << "enter the root node data " << endl;
   cin >> x;
   root=new node;
   root->data=x;
   root->lchild=root->rchild=NULL;
   enqueue(&q,root);
   while (!isEmpty(q))
   {
      p=dequeue(&q);
      cout<<"Enter lchild of "<<p->data<<" "<<endl;
      cin>>x;
      if(x!=-1)
      {
         t=new node;
         t->data=x;
         t->lchild=t->rchild=NULL;
         p->lchild=t;
         enqueue(&q,t);
      }
      cout<<"Enter rchild of "<<p->data<<" "<<endl;
      cin>>x;
      if(x!=-1)
      {
         t=new node;
         t->data=x;
         t->lchild=t->rchild=NULL;
         p->rchild=t;
         enqueue(&q,t);
      }
      
   }
   
}

void preorder(struct node *p)
{
   if(p)
   {
      cout<<p->data<<endl;
      preorder(p->lchild);
      preorder(p->rchild);
   
   }
}

void Ipreorder(struct node *p)
{  
   stack<node *> stk;

   while (p!=NULL || !stk.empty())
   {
      if(p!=NULL)
      {
         cout<<p->data<<" ";
          stk.push(p);
         p=p->lchild;
        
      }
      else{
           p=stk.top();
           stk.pop();
           p=p->rchild;

      }
      
   }
   
   
}

void inpreorder(struct node *p)
{  
   stack<node *> stk;

   while (p!=NULL || !stk.empty())
   {
      if(p!=NULL)
      {
        
          stk.push(p);
         p=p->lchild;
        
      }
      else{
           
           p=stk.top();
           stk.pop();
           cout<<p->data<<" ";
           p=p->rchild;

      }
      
   }
   
   
}


void levelorder(struct node *p)
{
   queue<node *> q;
   cout<<root->data<<" ";
   q.emplace(root);
   while(!q.empty())
   {
      
       p=q.front();
       q.pop();

       if(p->lchild){
       cout<<p->lchild->data<<" ";
       q.emplace(p->lchild);
       }
       if(p->rchild){
         cout<<p->rchild->data<<" ";
       q.emplace(p->rchild);
       }
   }
}
int main()
{  treeCreate();
  
   levelorder(root);

   return 0;
}