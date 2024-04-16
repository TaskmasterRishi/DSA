#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int l, int r)
{
    for (int i = l; i < r ; i++)
    {
        int smallest = i;
        for (int j = i; j < r ; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size;
    cout << "Enter size of an array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of an array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sort :";
    display(arr, size);
    selectionSort(arr, 0, size);
    cout << "After Sort : ";
    display(arr, size);
    return 0;
}