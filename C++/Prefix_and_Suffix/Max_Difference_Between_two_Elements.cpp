//
// Created by jishu on 19-10-2025.
//Max Difference between two Elements
#include<iostream>
#include <vector>
using namespace std;
int max_difference(vector<int>&nums) {
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for (int i=0;i<nums.size();i++) {
        maxi=max(nums[i],maxi);
        mini=min(nums[i],mini);
    }
    return maxi-mini;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The Element: ";
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<max_difference(arr);
}
