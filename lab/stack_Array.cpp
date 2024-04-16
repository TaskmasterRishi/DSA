#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class st
{
    int top;

public:
    int arr[MAX];
    st()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top == MAX)
        {
            cout << "Stack overflow " << endl;
        }
        else
        {
            arr[++top] = x;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int x = arr[top--];
            return x;
        }
    }

    int peep()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int x = arr[top];
            return x;
        }
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    st s;
    while (true)
    {
        cout << "Chosse Operation to perform \n 1. Push \n 2. Pop \n 3. Peep \n 4. Display \n 5. Exit"<<endl;
        int ans;
        cin >> ans;
        switch (ans)
        {
        case 1:
            int x;
            cout << "Enter element to add : ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            x = s.peep();
            cout << "Element at top : " << x << endl;
            break;

        case 4:
            s.display();

        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }

    return 0;
}