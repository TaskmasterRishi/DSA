#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // Memory Free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data : " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != element && curr != tail)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == tail && curr->data != element)
    {
        cout << "Element " << element << " not found in the list." << endl;
        return;
    }

    if (curr == tail) // If the element to delete is tail
    {
        if (prev == tail) // If there's only one node
        {
            delete curr;
            tail = NULL;
        }
        else
        {
            prev->next = curr->next;
            tail = prev; // Update tail to the previous node
            delete curr;
        }
    }
    else
    {
        prev->next = curr->next;
        delete curr;
    }
}


void print(Node *&tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    deleteNode(tail, 10);
    insertNode(tail, 0, 10);
    print(tail);
    insertNode(tail, 10, 20);
    print(tail);
    insertNode(tail, 20, 30);
    print(tail);
    insertNode(tail, 10, 15);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    deleteNode(tail, 30);
    print(tail);
    deleteNode(tail, 20);
    print(tail);
    deleteNode(tail, 15);
    print(tail);
    return 0;
}