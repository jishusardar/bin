//
// Created by jishu on 18-10-2025.
//bubble sort
#include<iostream>
#include <vector>
using namespace std;
void Bubble_sort(vector<int>&arr) {
    for (int i=arr.size()-1;i>=0;i--) {
        for (int j=0;j<=i;j++) {
            if (arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    Bubble_sort(arr);
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
