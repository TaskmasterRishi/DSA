#include<iostream>
#define N 100
using namespace std;
class queue
{
    int arr[N],front,rear;
    public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int x)
    {
        if(rear == N-1)
        {
            cout<<"Queue overflow"<<endl;
        }
        else if(front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Queue underflow"<<endl;
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    void display()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"Queue elements"<<endl;
            for(int i = front;i<=rear;i++)
            {
                cout<<arr[i]<<endl;
            }
        }
    }
};
int main()
{
    queue q;
    int a,c;
    do{
    cout<<"Select operation:\n1 for push\n2 for pop\n3 for  display\n4 for exit"<<endl;
    cin>>c;
    
    switch(c)
    {
        case 1: 
            cout<<"Enter the element to push: ";
            cin>>a;
            q.enqueue(a);
            break;
        case 2:
            cout<<"Popped";
            q.dequeue();
            break;
        case 3:
            cout<<"Display"<<endl;
            q.display();
            break;
        case 4:
            cout<<"EXIT"<<endl;
            break;
        default:
            break;
    }
    }
    while(c!=4);
    return 0;
}