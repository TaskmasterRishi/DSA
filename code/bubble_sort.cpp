#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int l, int r)
{
    for (int i = l; i < r - 1; i++)
    {
        for (int j = l; j < r - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
    }
}

int main()
{
    int arr[10] = {1, 4, 12, 86, 69, 45, 12, 14};
    int n = 8;
    bubbleSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}