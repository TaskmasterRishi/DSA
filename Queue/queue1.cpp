#include <bits/stdc++.h>
using namespace std;

class qu
{
    int front = -1, rear = -1, size;
    int *a;

public:
    qu(int size)
    {
        this->size = size;
        a = new int[size];
    }

    void push(int x);
    void pop();
    int peep();
    bool isEmpty();
    void display();
};

void qu::push(int x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        a[rear] = x;
    }
}

void qu::pop()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    else
    {
        a[front]=0;
        if (front == rear)
        {
            front = rear = -1;
        }
        front++;
    }
}

bool qu::isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

int qu::peep()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        cout << "element at front is:" << a[front] << endl;
        return a[front];
    }
}

void qu::display()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        for (int i = front; i <= rear; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    n = 10;
    qu q(n);
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    // q.peep();
    // q.pop();
    while (true)
    {
        cout << " 1 -> Insert \n 2 -> Delete \n 3 -> Display \n 4 -> exit"<<endl;
        cout << "Enter choice"<<endl;
        int ans;
        cin >> ans;
        if (ans == 1)
        {
            int x;
            cout << "Enter element";
            cin >> x;
            q.push(x);
        }
        else if(ans == 2){
            q.pop();
        }
        else if(ans == 3){
            q.display();
        }
        else {
            exit(0);
        }
    }
    return 0;
}
