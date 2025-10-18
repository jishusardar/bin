//
// Created by jishu on 18-10-2025.
//fibonachi
#include<iostream>
#include <vector>
using namespace std;
int fibonachi(vector<int>&arr,int n) {
    for (int i=2;i<n;i++) {
        arr.push_back(arr[i-1]+arr[i-2]);
    }
    return arr[n-1];
}
int main() {
    int n;
    cout<<"Entre The Term: ";
    cin>>n;
    vector<int>arr(2,0);
    arr[1]=1;
    cout<<fibonachi(arr,n);
}
