//
// Created by jishu on 18-10-2025.
//Separate Cows in The Cattle
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
int Aggressive_Cows(vector<int>&nums,int k) {
    sort(nums.begin(),nums.end());
    int start=1,end=nums[nums.size()-1]-nums[0],ans;
    while (start<=end) {
        int mid=start+(end-start)/2;
        int count=1,pos=nums[0];
        for (int i=1;i<nums.size();i++) {
            if (pos+mid<=nums[i]) {
                pos=nums[i];
                count++;
            }
        }
        if (count>=k) {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
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
    cout<<"Entre The Cows: ";
    cin>>k;
    cout<<Aggressive_Cows(arr,k);
}
