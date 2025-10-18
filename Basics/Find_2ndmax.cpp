//
// Created by jishu on 18-10-2025.
//Find Second Maximum Element
#include<iostream>
#include <vector>
using namespace std;
int Find_2nd_max(vector<int>&arr) {
    int max1=INT_MIN;
    for (int i=0;i<arr.size();i++) {
        max1=max(max1,arr[i]);
    }
    int maxf=INT_MIN;
    for (int i=0;i<arr.size();i++) {
        if (arr[i]!=max1)
        maxf=max(maxf,arr[i]);
    }
    return maxf;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Find_2nd_max(arr);
}
