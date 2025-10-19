//
// Created by jishu on 19-10-2025.
//segregate 0 and 1
#include<iostream>
#include <vector>
using namespace std;
void segregate(vector<int>&nums) {
    int start=0,end=nums.size()-1;
    while (start<=end) {
        if (nums[start]==0)
            start++;
        if (nums[end]==1)
            end--;
        if (nums[start]==1&&nums[end]==0) {
            swap(nums[start],nums[end]);
            start++,end--;
        }
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    segregate(arr);
    cout<<"The Final Array is: "<<endl;
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
