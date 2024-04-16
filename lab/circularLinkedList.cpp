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

class circular
{
    node *head;

public:
    circular()
    {
        head = NULL;
    }

    void insertAtSatrt(int data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head; 
            return;
        }
        node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = head; 
        head = newNode;
    }

    void insertAtEnd(int data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head; 
            return;
        }
        node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = head; 
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
            node *ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head->next;
            head = head->next;
            delete temp;
            return;
        }
        node *ptr = head;
        node *preptr = NULL;
        while (ptr->next != head && ptr->data != data)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr->data != data)
        {
            cout << "Value not found in the list" << endl;
            return;
        }
        preptr->next = ptr->next;
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
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    circular list;
    while (true)
    {
        cout << " 1) Insert at start \n 2) Insert at End \n 3) Delete Node \n 4) Print \n 5) Exit \n Enter your choice: ";
        int choice;
        cin >> choice;
        int data;
        switch (choice)
        {
        case 1:
            cout << "Enter data value: ";
            cin >> data;
            list.insertAtSatrt(data);
            break;

        case 2:
            cout << "Enter data value: ";
            cin >> data;
            list.insertAtEnd(data);
            break;

        case 3:
            cout << "Enter data value to be deleted: ";
            cin >> data;
            list.remove(data);
            break;

        case 4:
            list.print();
            break;

        case 5:
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
