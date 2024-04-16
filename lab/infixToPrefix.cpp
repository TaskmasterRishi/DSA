#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int precedence(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixbackostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    vector<char> char_stack;
    string prefix;

    for (int i = 0; i < l; i++)
    {

        if (isalpha(infix[i]) || isdigit(infix[i]))
            prefix += infix[i];

        else if (infix[i] == '(')
            char_stack.push_back('(');

        else if (infix[i] == ')')
        {
            while (char_stack.back() != '(')
            {
                prefix += char_stack.back();
                char_stack.pop_back();
            }

            char_stack.pop_back();
        }
        else
        {
            if (isOperator(char_stack.back()))
            {
                if (infix[i] == '^')
                {
                    while (
                        precedence(infix[i]) <= precedence(char_stack.back()))
                    {
                        prefix += char_stack.back();
                        char_stack.pop_back();
                    }
                }
                else
                {
                    while (
                        precedence(infix[i]) < precedence(char_stack.back()))
                    {
                        prefix += char_stack.back();
                        char_stack.pop_back();
                    }
                }
                char_stack.push_back(infix[i]);
            }
        }
    }
    while (!char_stack.empty())
    {
        prefix += char_stack.back();
        char_stack.pop_back();
    }
    return prefix;
}

string infixbackrefix(string infix)
{
    int l = infix.size();

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string prefix = infixbackostfix(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string s = ("K+L-M*N");

    cout << infixbackrefix(s) << std::endl;
    return 0;
}
