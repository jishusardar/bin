//
// Created by jishu on 18-10-2025.
//rotate array by 1
#include<iostream>
#include <vector>
using namespace std;
void rotate_by_1(vector<int>&arr) {
    int temp=arr[arr.size()-1];
    for (int i=arr.size()-1;i>0;i--) {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    rotate_by_1(arr);
    for (int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}