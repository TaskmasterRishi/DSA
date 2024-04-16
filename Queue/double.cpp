#include <bits/stdc++.h>
using namespace std;

class doublyQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    doublyQueue()
    {
        size = 1000;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((rear == size - 1 && front == 0) || (front != 0 && rear == (front - 1) % (size - 1))) // full or not
            return true;
        else
            return false;
    }

    bool push_front(int x)
    {
        if (isFull()) // full or not
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (isEmpty()) // first push
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1) // circular
        {
            front = size - 1;
        }
        else // normal
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool push_back(int x)
    {
        if (isFull()) // full or not
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (isEmpty()) // first push
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) // circular
        {
            rear = 0;
        }
        else // normal
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int pop_front()
    {
        if (isEmpty()) // empty or not
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = NULL;
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

    int pop_back()
    {
        if (isEmpty()) // empty or not
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = NULL;
        if (front == rear) // single Element
        {
            front = rear = -1;
        }
        else if (rear == 0) // circular
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getBack()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }
};

int main()
{

    return 0;
}