#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int l, int r)
{
    for (int i = l; i < r - 1; i++)
    {
        for (int j = l; j < r - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    cout<<"Enter the elements of array : "<<endl;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted Array"<<endl;
    display(arr,size);
    cout<<endl;
    cout<<"Sorted Array"<<endl;
    bubbleSort(arr,0,size);
    display(arr,size);
    return 0;
}