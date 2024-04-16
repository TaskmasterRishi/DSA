#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> arr){
    for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
}

int main(){
    vector<int> arr;
    cout<<"Enter the size of array : ";
    int n,position;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"choose \n 1. Delete obeject \n 2. Enter Element"<<endl;
    int ans;
    cin>>ans;
        if(ans == 1){
            cout<<"Enter position : ";
            cin>>position;
            arr.erase(arr.begin() + position);
        }
        else if(ans == 2){
            cout<<"Enter position : ";
            cin>>position;
            cout<<"Enter th number : ";
            int temp;
            cin>>temp;
            arr.insert(arr.begin()+position,temp);
        }
        else{
            exit (0);
        }

    display(arr);
    return 0;
}