#include <bits/stdc++.h>
using namespace std;

int partision(int arr[], int l, int r)
{
    int pivot = arr[l];
    int count = 0;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = l + count;
    swap(arr[pivotIndex], arr[l]);
    int i = l, j = r;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partision(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
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
    cout << "Enter the size of an array : ";
    cin >> size;
    int arr[size];
    cout << "Enter elements of an array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Unsorted Array : ";
    display(arr, size);
    quickSort(arr, 0, size - 1);
    cout << "Sorted Array : ";
    display(arr, size);
    return 0;
}