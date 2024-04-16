#include <bits/stdc++.h>
using namespace std;

class circularQueue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    circularQueue()
    {
        size = 10000;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int x)
    {
        if ((rear == size - 1 && front == 0) || (rear == (front - 1) % (size - 1))) // full or not
        {
            cout << "Queue is full" << endl;
            exit(1);
        }
        else if (front == -1) // first insert
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) // circular
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    int dequeue()
    {
        if (front == -1) // empty or not
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) // single Element
        {
            front = rear = -1;
        }
        else if (front == size - 1) // circular
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}