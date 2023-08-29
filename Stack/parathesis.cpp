#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s)
{
    stack<char> stk;
    stk.size();
    
    for (int i = 0; i < '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stk.push(s[i]);
            
            
        }
        else if (s[i] == ')' && stk.t == '(')
        {

           stk.pop();
        }
        else if (s[i] == ']' && stk.top() == '[')
        {

            stk.pop();
        }
        else if (s[i] == '}' && stk.top() == '{')
        {

            stk.pop();
        }
        else
        {
            return "No";
        }
    }
    if (stk.empty())
    {
        return "yes";
    }

    return "no";
}

int main()
{
    cout << isBalanced("({[(]})");
    
    return 0;
}