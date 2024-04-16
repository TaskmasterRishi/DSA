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

void insertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node *&Head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(Head, d);
        if (Head->next == NULL) // If there was only one node before, update tail
            tail = Head;
        return;
    }
    Node *temp = Head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    if (nodeToInsert->next == NULL) // If the inserted node becomes the new tail, update tail pointer
        tail = nodeToInsert;
}

void deleteNode(int pos, Node *&Head, Node *&tail)
{
    if (pos == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = Head;
        Node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL) // The node to be deleted is the last node
        {
            prev->next = NULL;
            tail = prev;
        }
        else
            prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main()
{
    Node *Node1 = new Node(10);
    Node *Head = Node1;
    Node *tail = Node1;
    print(Head);
    insertAtTail(tail, 5);
    print(Head);
    insertAtTail(tail, 6);
    print(Head);
    insertAtTail(tail, 4);
    print(Head);
    insertAtPosition(Head, tail, 5, 20);
    print(Head);
    cout << "Head : " << Head->data << endl;
    cout << "Tail : " << tail->data << endl;
    deleteNode(1, Head, tail);
    print(Head);
    cout << "Head : " << Head->data << endl;
    cout << "Tail : " << tail->data << endl;
    return 0;
}