//
// Created by jishu on 18-10-2025.
//Search Element in a rotated array
#include<iostream>
#include <vector>
using namespace std;
bool Search_in_Rotated(vector<int>&nums,int val) {
    int start=0,end=nums.size()-1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (nums[mid]==val)
            return 1;
        else if (nums[mid]>=nums[0]) {
            if (nums[start]<=val&&nums[mid]>val)
                end=mid-1;
            else
                start=mid+1;
        }
        else {
            if (nums[mid]<val&&nums[end]>=val)
                start=mid+1;
            else
                end=mid-1;
        }
    }
    return 0;
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
    cout<<Search_in_Rotated(arr,val);
}
