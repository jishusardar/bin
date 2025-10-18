//
// Created by jishu on 18-10-2025.
//ship packages in m days
#include<iostream>
#include <vector>
using namespace std;
int ship_packages(vector<int>&nums,int m) {
    int start=INT_MIN,end=0,ans;
    for (int i=0;i<nums.size();i++) {
        start=max(start,nums[i]);
        end+=nums[i];
    }
    while (start<=end) {
        int mid=start+(end-start)/2;
        int weight=0,days=1;
        for (int i=0;i<nums.size();i++) {
            weight+=nums[i];
            if (weight>mid) {
                weight=nums[i];
                days++;
            }
        }
        if (days>m) {
            start=mid+1;
        }
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
    int m;
    cout<<"Entre The no of Days: ";
    cin>>m;
    cout<<ship_packages(arr,m);
}
