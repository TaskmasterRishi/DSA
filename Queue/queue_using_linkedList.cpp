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

class qu
{
    node *front, *rear;

public:
    qu()
    {
        front = rear = NULL;
    }

    void push(int);
    int pop();
    int peep();
    bool isEmpty();
    void display();
};

bool qu::isEmpty()
{
    return (front == NULL);
}

void qu::push(int data)
{
    node *temp = new node(data);
    if (!temp)
    {
        cout << "Satck Overrlow";
    }
    if (rear = NULL)
    {
        front = rear = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
}

int qu::pop()
{
    if (isEmpty())
    {
        cout << "Stack Unerrlow";
        exit(1);
    }
    else
    {
        node *temp = front;
        int x = temp->data;
        front = front->link;
        delete(temp);
        return x;
    }
}

int qu::peep(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{

    }
}

int main()
{

    return 0;
}