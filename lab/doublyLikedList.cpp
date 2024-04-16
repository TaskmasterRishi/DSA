#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class doubly
{
    node *head;

public:
    doubly()
    {
        head = NULL;
    }

    void insertAtStart(int data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }

    void insertBefore(int data, int value)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        if (head->data == value)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        node *ptr = head;
        while (ptr != NULL && ptr->next->data != value)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
    }

    void insertAfter(int data, int value)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        node *ptr = head;
        while (ptr != NULL && ptr->data != value)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }
        newNode->next = ptr->next;
        if(ptr->next!=NULL)
            ptr->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
    }

    void remove(int data)
    {
        if (head == NULL)
        {
            cout << "Under Flow" << endl;
            return;
        }
        if (head->data == data)
        {
            node *temp = head;
            head = head->next;
            head->prev=NULL;
            delete temp;
            return;
        }
        node *ptr = head;
        while (ptr != NULL && ptr->data != data)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }
        if(ptr->next!=NULL)
            ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        delete ptr;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    doubly list;
     while (true)
    {
        cout << " 1) Insert at head \n 2) Insert at tail \n 3) Insert after node \n 4) Insert before node \n 5) Delete Node \n 6) Print \n 7) Exit \n Enter your choice: ";
        int choice;
        cin >> choice;
        int data;

        int value;
        switch (choice)
        {
        case 1:
            cout << "Enter data value: ";
            cin >> data;
            list.insertAtStart(data);
            break;

        case 2:
            cout << "Enter data value: ";
            cin >> data;
            list.insertAtEnd(data);
            break;

        case 3:
            cout << "Enter data value: ";
            cin >> data;
            cout << "Enter data value of node after which you want to insert: ";
            cin >> value;
            list.insertAfter(data, value);
            break;

        case 4:
            cout << "Enter data value: ";
            cin >> data;
            cout << "Enter data value of node before which you want to insert: ";
            cin >> value;
            list.insertBefore(data, value);
            break;

        case 5:
            cout << "Enter data value to be deleted: ";
            cin >> data;
            list.remove(data);
            break;

        case 6:
            list.print();
            break;

        case 7:
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
            exit(0);
            break;
        }
    }
    return 0;
}
