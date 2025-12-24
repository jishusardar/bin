//
// Created by jishu on 18-10-2025.
//selection sort
#include<iostream>
#include <vector>
using namespace std;
void Selection_Sort(vector<int>&nums) {
    for (int i=1;i<nums.size();i++) {
        for (int j=i;j<nums.size();j++) {
            if (nums[j]<nums[j-1])
                swap(nums[j],nums[j-1]);
        }
    }
}
int main() {
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    Selection_Sort(arr);
    for (int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
