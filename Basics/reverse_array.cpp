//
// Created by jishu on 18-10-2025.
//Reverse Array
#include<iostream>
#include <vector>
using namespace std;
void reverse_array(vector<int>&arr) {
    int start=0,end=arr.size()-1;
    while (start<end) {
        swap(arr[start],arr[end]);
        start++,end--;
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Numbers: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    reverse_array(arr);
    for (int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
}
