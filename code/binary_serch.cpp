#include <bits/stdc++.h>
using namespace std;
vector<int> binarySearch(vector<int> arr, int l, int r, int x)
{
    vector<int> indices;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            indices.push_back(mid);
            int left = mid - 1;
            while (left >= l && arr[left] == x)
            {
                indices.push_back(left);
                left--;
            }
            int right = mid + 1;
            while (right <= r && arr[right] == x)
            {
                indices.push_back(right);
                right++;
            }
            return indices;
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return indices;
}

int main(void)
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;
    vector<int> result = binarySearch(arr, 0, size - 1, target);
    if (result.empty())
        cout << "Element is not present in array";
    else
    {
        cout << "Element is present at indices: ";
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
            if (i < result.size() - 1)
                cout << ", ";
        }
    }
    return 0;
}