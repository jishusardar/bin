//
// Created by jishu on 19-10-2025.
//Pair with given difference
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
vector<int>pair_with_diff(vector<int>&nums,int diff) {
    sort(nums.begin(),nums.end());
    vector<int>ans(2,-1);
    for (int i=0;i<nums.size()-1;i++) {
        int target=diff+nums[i];
        int start=i,end=nums.size()-1;
        while (start<=end) {
            int mid=start+(end-start)/2;
            if (nums[mid]==target) {
                ans[0]=nums[i];
                ans[1]=nums[mid];
                return ans;
            }
            else if (nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The Element: ";
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int diff;
    cout<<"Entre The Difference: ";
    cin>>diff;
    vector<int>ans=pair_with_diff(arr,diff);
    cout<<ans[0]<<" "<<ans[1];
}
