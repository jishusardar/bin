//
// Created by jishu on 18-10-2025.
//Find Element
#include<iostream>
#include <vector>
using namespace std;
bool Find_Element(vector<int>&arr,int val) {
    int start=0,end=arr.size()-1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (arr[mid]==val)
            return 1;
        else if (arr[mid]>val)
            end=mid-1;
        else
            start=mid+1;
    }
    return 0;
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
    cout<<"Entre The Element: ";
    cin>>val;
    cout<<Find_Element(arr,val);
}
