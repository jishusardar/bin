//
// Created by jishu on 18-10-2025.
//Find Missing Number
#include<iostream>
#include <vector>
using namespace std;
int Find_Missing_number(vector<int>&arr) {
    for (int i=0;i<arr.size()-1;i++) {
        if (arr[i]+1!=arr[i+1])
            return arr[i]+1;
    }
    return arr[arr.size()-1]+1;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Find_Missing_number(arr);
}
