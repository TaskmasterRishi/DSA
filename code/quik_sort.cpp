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

int main()
{
    int arr[10] = {1, 45, 12, 86, 69, 45, 12, 14};
    int n = 8;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}