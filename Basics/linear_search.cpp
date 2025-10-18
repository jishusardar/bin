//
// Created by jishu on 18-10-2025.
//search for element in array
#include<iostream>
#include <vector>
using namespace std;
int Find_Element(vector<int>&nums,int val) {
    for (int i=0;i<nums.size();i++) {
        if (nums[i]==val)
            return i;
    }
    return -1;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int val;
    cout<<"Entre Element To Find: ";
    cin>>val;
    cout<<Find_Element(arr,val);
}
