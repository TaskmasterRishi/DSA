#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        this->data = 0;
        this->next = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class singly
{
    node *head;

public:
    singly()
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
        newNode->next = head;
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
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
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
        ptr->next = newNode;
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
        ptr->next = newNode;
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
            delete temp;
            return;
        }
        node *ptr = head;
        node *preptr = NULL;
        while (ptr != NULL && ptr->data != data)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }
        preptr->next = ptr->next;
        delete ptr;
    }

    void print()
    {
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
    singly list;
    // while (true)
    // {
    //     cout << " 1) Insert at head \n 2) Insert at tail \n 3) Insert after node \n 4) Insert before node \n 5) Delete Node \n 6) Print \n 7) Exit \n Enter your choice: ";
    //     int choice;
    //     cin >> choice;
    //     int data;

    //     int value;
    //     switch (choice)
    //     {
    //     case 1:
    //         cout << "Enter data value: ";
    //         cin >> data;
    //         list.insertAtStart(data);
    //         break;

    //     case 2:
    //         cout << "Enter data value: ";
    //         cin >> data;
    //         list.insertAtEnd(data);
    //         break;

    //     case 3:
    //         cout << "Enter data value: ";
    //         cin >> data;
    //         cout << "Enter data value of node after which you want to insert: ";
    //         cin >> value;
    //         list.insertAfter(data, value);
    //         break;

    //     case 4:
    //         cout << "Enter data value: ";
    //         cin >> data;
    //         cout << "Enter data value of node before which you want to insert: ";
    //         cin >> value;
    //         list.insertBefore(data, value);
    //         break;

    //     case 5:
    //         cout << "Enter data value to be deleted: ";
    //         cin >> data;
    //         list.remove(data);
    //         break;

    //     case 6:
    //         list.print();
    //         break;

    //     case 7:
    //         exit(0);
    //         break;

    //     default:
    //         cout << "Invalid choice" << endl;
    //         exit(0);
    //         break;
    //     }
    //     list.print();
    // }
    list.insertAtStart(4);
    list.insertAtEnd(12);
    list.insertAfter(8,4);
    list.insertBefore(9,12);
    list.print();
    list.remove(4);
    list.print();
    return 0;
}
