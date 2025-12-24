//
// Created by jishu on 18-10-2025.
//Search Inert Positions
#include<iostream>
#include <vector>
using namespace std;
int search_inert_pos(vector<int>&arr,int val) {
    int start=0,end=arr.size()-1,ans;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (arr[mid]==val)
            return mid;
        else if (arr[mid]>val) {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int val;
    cout<<"Entre The value: ";
    cin>>val;
    cout<<search_inert_pos(arr,val);
}
