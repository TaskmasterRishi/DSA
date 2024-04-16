#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAlphanumeric(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    else if (c >= 'A' && c <= 'Z')
        return true;
    else if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    string postfix;
    vector<char> operators;

    for (int i = 0; i < infix.size(); i++)
    {
        char c = infix[i];
        if (c == '(')
        {
            operators.push_back(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.back() != '(')
            {
                postfix += operators.back();
                operators.pop_back();
            }
            operators.pop_back();
        }
        else if (isAlphanumeric(c))
        {
            postfix += c;
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && precedence(operators.back()) >= precedence(c))
            {
                postfix += operators.back();
                operators.pop_back();
            }
            operators.push_back(c);
        }
    }
    while (!operators.empty())
    {
        postfix += operators.back();
        operators.pop_back();
    }
    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter infix expresion : "<<endl;
    cin>>infix;
    string postfix = infixToPostfix(infix);
    cout <<"Postfix expression: " << postfix<<endl;
    return 0;
}