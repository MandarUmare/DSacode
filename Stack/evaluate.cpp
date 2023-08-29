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
    if (x == '+' || x == '*' || x == '/' || x == '-' || x == '#')
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
    if (isOperand(x))
    {
        return 3;
    }

    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void create(stack *st, char *p)
{

    st->size = strlen(p);
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
    char *postfix = new char[strlen(infix) + 1];
    push(st, '#');

    while (infix[i] != '\0')
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
    while (isEmpty(*st) != 1)
    {
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';

    return postfix;
}

int evaluate(stack *st, char *infix)
{
    int i = 0;
    int r;
    int x1 = 0, x2 = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
        {
            push(st, infix[i++] - '0');
        }
        else
        {

            x2 = pop(st);
            x1 = pop(st);
            switch (infix[i])
            {
            case '+':
                r = x1 + x2;
                push(st, r);
                break;
            case '*':
                r = x1 * x2;
                push(st, r);
                break;
            case '-':
                r = x1 - x2;
                push(st, r);
                break;
            case '/':
                r = x1 / x2;
                push(st, r);
                break;
            }
        }
    }

    return pop(st);
}

int main()
{
    struct stack st;

    char *infix = "556*+88/-#";
    create(&st, infix);

    int p;
    p = evaluate(&st, infix);

    cout << p;

    return 0;
}