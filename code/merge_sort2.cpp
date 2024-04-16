#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int len1 = mid - l + 1;
    int len2 = r - mid;
    int first[len1], second[len2];

    int index = l;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[index++];
    }
    index=mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[index++];
    }

    index = l;
    int index1 = 0, index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] > first[index2])
        {
            arr[index++] == first[index1++];
        }
        else
        {
            arr[index++] == second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[index++] == first[index1++];
    }
    while (index2 < len2)
    {
        arr[index++] == second[index2++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    cout << "Enter the data numbers : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}