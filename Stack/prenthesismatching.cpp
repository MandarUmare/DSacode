#include <iostream>
#include <string.h>
using namespace std;

struct stack
{
    int size;
    int top;
    char *s;
};

int isOperand(char x)
{
    if (x == '+' || x == '*' || x == '/' || x == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int presidence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

void create(stack *st,char* p)
{
   
    st->size=strlen(p);
    st->top = -1;
    st->s = new char[st->size + 1];
}

void display(stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << endl;
    }
}

void push(stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

char pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

char peek(stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0 || pos < 0)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int isEmpty(stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char stackTop(stack st)
{
    if (st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}

char *toPostfix(stack *st, char *infix)
{
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix)];
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (presidence(infix[i]) > presidence(stackTop(*st)))
            {
                push(st, infix[i++]);
            }
           
            else
            {
                postfix[j++] = pop(st);
            }
        }
    }
    while (isEmpty(*st)!=1)
    {
        postfix[j++] = pop(st);
    }
    postfix[j]='\0';

    return postfix;
}


int main()
{
    struct stack st;

 
    char *infix = "a+b*c-d/e";
       create(&st,infix);

    char *p;
    p = toPostfix(&st, infix);


    for (char i = 0; i <strlen(p); i++)
    {
        cout << p[i];
    }

    return 0;
}