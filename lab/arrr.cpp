#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void remove(int arr[], int &size, int position)
{
    if (position >= 0 && position < size)
    {
        for (int i = position; i < size - 1; i++)
        {
            arr[i] = arr[i + 1]; 
        }
        size--; 
    }
    else
    {
        cout << "Invalid position for deletion." << endl;
    }
}

void insert(int arr[], int &size, int element, int position)
{
    if (position >= 0 && position <= size)
    {
        for (int i = size; i > position; i--)
        {
            arr[i] = arr[i - 1]; 
        }
        arr[position] = element; 
        size++;                 
    }
    else
    {
        cout << "Invalid position for insertion." << endl;
    }
}

int main()
{
    int arr[100]; 
    int size;

    cout << "Enter the size of array: ";
    cin >> size;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int ans;
    while (true)
    {
        cout << "Choose: \n 1. remove object \n 2. Enter Element \n 3. exit" << endl;
        cin >> ans;
        if (ans == 1)
        {
            int position;
            cout << "Enter position: ";
            cin >> position;
            remove(arr, size, position);
        }
        else if (ans == 2)
        {
            int position, element;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter the number: ";
            cin >> element;
            insert(arr, size, element, position);
        }
        else if(ans == 3){
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        display(arr, size);
    }
    return 0;
}
