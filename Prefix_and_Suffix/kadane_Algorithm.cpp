//
// Created by jishu on 19-10-2025.
//if prefix is less than 0 set prefix 0
#include<iostream>
#include <vector>
using namespace std;
int Largest_Sum_Contigous(vector<int>&nums) {
    int ans=INT_MIN,sum=0;
    for (int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if (sum<0)
            sum=0;
        ans=max(ans,sum);
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
    cout<<Largest_Sum_Contigous(arr);
}
