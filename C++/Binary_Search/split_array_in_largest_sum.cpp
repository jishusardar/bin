//
// Created by jishu on 18-10-2025.
//split array in largest sum
#include<iostream>
#include <vector>
using namespace std;
int Split_array_in_largest_sum(vector<int>&nums,int k) {
    int start=0,end=0,ans;
    for (int i=0;i<nums.size();i++) {
        start=max(start,nums[i]);
        end+=nums[i];
    }
    while (start<=end) {
        int mid=start+(end-start)/2;
        int sum=0,split=1;
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if (sum>mid) {
                sum=nums[i];
                split++;
            }
        }
        if (split>k)
            start=mid+1;
        else {
            ans=mid;
            end=mid-1;
        }
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
    int k;
    cout<<"Entre The Split Ways: ";
    cin>>k;
    cout<<Split_array_in_largest_sum(arr,k);
}
