#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *s;

};

void create(stack *st){ 
    cout<<"Enter the size of stack"<<endl;
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];
    
      
}

void display(stack st)
{
    for (int i =st.top;i>=0;i--)
    {
        cout<<st.s[i]<<endl;
    }
    
}

void push(stack *st,int x)
{
    if(st->top==st->size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}


int pop(stack *st)
{  int x=-1;
   if(st->top==-1){
    cout<<"Stack Underflow"<<endl;
   }
   else{
     x=st->s[st->top--];
   }
   return x;
}

int peek(stack st,int pos)
{   int x=-1;
    if(st.top-pos+1<0 || pos<0){
        cout<<"Invalid position"<<endl;

    }else{
        x=st.s[st.top-pos+1];
    }
    return x;
}


int isEmpty(stack st)
{
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack st){
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stackTop(stack st)
{
    if(st.top==-1){
        return -1;
    }else{
        return st.s[st.top];
    }
}

int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    cout<<isFull(st)<<endl;
    cout<<peek(st,5)<<endl;
    display(st);
    cout<<stackTop(st);


return 0;
}