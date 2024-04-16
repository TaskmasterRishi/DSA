#include <bits/stdc++.h>
using namespace std;
#define max 100

class st
{
    int top;

public:
    int arr[max];
    st()
    {
        top = -1;
    }
    void push(int x);
    int pop();
    int peek();
    bool empty();
};

void st::push(int x)
{
    if (top == max)
    {
        cout << "Stack Overflow";
    }
    else
    {
        arr[++top] = x;
    }
}

int st::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

int st::peek()
{
    if (top < 0)
    {
        cout << "Stack is empty";
        return 0;
    }
    else
    {
        int x = arr[top];
        return x;
    }
}

bool st::empty()
{
    return (top < 0);
}

int main()
{
    st s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.pop() << endl;
    if (!s.empty())
    {
        cout << s.peek() << endl;
        s.pop();
    }
    return 0;
}