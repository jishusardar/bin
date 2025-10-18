//
// Created by jishu on 18-10-2025.
//Peak Index in mountain array
#include<iostream>
#include <vector>
using namespace std;
int peakindex(vector<int>&nums) {
    int start=0,end=nums.size()-1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
            return mid;
        else if (nums[mid]>nums[mid+1])
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}
int main() {
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Number: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<peakindex(arr);
}
