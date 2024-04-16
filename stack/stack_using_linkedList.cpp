#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *link;
    node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};

class st
{
    node *top;

public:
    st() { top = NULL; }

    void push(int data);
    int pop();
    int peep();
    bool isEmpty();
    void display();
};

void st::push(int data)
{
    node *temp = new node(data);
    if (!temp)
    {
        cout << "Stack Overflow";
    }
    else
    {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

bool st::isEmpty()
{
    return top == NULL;
}

int st::pop()
{
    node *temp;
    if (isEmpty())
    {
        cout << "Stack is Empty";
        return -1;
    }
    else
    {
        int x = top->data;
        temp = top;
        top = top->link;
        free(temp);
        return x;
    }
}

int st::peep()
{
    if (!isEmpty())
    {
        cout<<top->data<<endl;
        return top->data;
    }
    else
    {
        cout << "Stack is Empty";
        return -1;
    }
}

void st::display()
{
    node *temp;
    if (isEmpty())
    {
        cout << "Stack Underflow";
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout<<temp->data;
            temp = temp->link;
            if(temp != NULL){
                cout<<" -> ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    st s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    s.peep();
    s.display();
    return 0;
}