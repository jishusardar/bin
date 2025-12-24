//
// Created by jishu on 19-10-2025.
//Largest Sum Contigous Subarray
#include<iostream>
#include <vector>
using namespace std;
int largest_Sum_Contigous(vector<int>&nums) {
    int sum=0,ans=INT_MIN;
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
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<largest_Sum_Contigous(arr);
}
