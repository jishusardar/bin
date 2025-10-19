//
// Created by jishu on 19-10-2025.
//divide array in 2 subarray with equal sum
#include<iostream>
#include <vector>
using namespace std;
int Divide_array(vector<int>&nums) {
    int sum1=0,sum2=0;
    for (int i=0;i<nums.size();i++)
        sum1+=nums[i];
    for (int i=0;i<nums.size();i++) {
        sum2+=nums[i];
        int target=sum1-sum2;
        if (sum2==target)
            return i;
    }
    return -1;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Divide_array(arr);
}
