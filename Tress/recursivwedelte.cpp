#include <iostream>
#include <queue>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

int height(node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
        {
            return x + 1;
        }
        if (y > x)
        {
            return y + 1;
        }
    
}

node *inPre(node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

node *inSucc(node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}
node *Delete(node *p, int data)
{
    struct node *q;
    if (p == NULL)
    {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == NULL)
        {
            root = NULL;
        }

        delete p;
        return nullptr;
    }
    if (data < p->data)
    {
        p->lchild=Delete(p->lchild,data);
    }
    else if (data > p->data)
    {
        p->rchild=Delete(p->rchild,data);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void create()
{
    struct node *p, *t;
    queue<node *> q;
    int x;
    cout << "Enter the root node data " << endl;
    cin >> x;
    root = new node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter the lchild of the " << p->data << " " << endl;
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.emplace(t);
        }
        cout << "Enter the rchild of the " << p->data << " " << endl;
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void preorder(struct node *p)
{

    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{

    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

int main()
{

    create();
    Delete(root, 8);
    inorder(root);
    preorder(root);
    return 0;
}