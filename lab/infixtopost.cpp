#include <bits/stdc++.h>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return -1;
}

// infix to postfix
string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}
// infix to prefix
string infixToPrefix(string infix)
{
    string prefix = "";
    stack<char> s;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            prefix += c;
        }
        else if (c == ')')
        {
            s.push(c);
        }
        else if (c == '(')
        {
            while (!s.empty() && s.top() != ')')
            {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == ')')
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && precedence(c) < precedence(s.top()))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix;
    cout << "Enter the infix expression without the space between" << endl;
    cin >> infix;
    cout << "Prefix is" << infixToPrefix(infix) << endl;
    cout << "Postfix is" << infixToPostfix(infix) << endl;
    return 0;
}