//
// Created by jishu on 19-10-2025.
//Two Sums
#include<iostream>
#include <vector>
using namespace std;
vector<int>Two_Sums(vector<int>&arr,int sum) {
    vector<int>ans(2,-1);
    for (int i=0;i<arr.size()-1;i++) {
        int target=sum-arr[i];
        int start=i,end=arr.size()-1;
        while (start<=end) {
            int mid=start+(end-start)/2;
            if (arr[mid]==target) {
                ans[0]=arr[i];
                ans[1]=arr[mid];
                return ans;
            }
            else if (arr[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
    }
    return ans;
    //time complexity O(nlongn)
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The Element: ";
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cout<<"Entre The Sum: ";
    cin>>sum;
    vector<int>ans=Two_Sums(arr,sum);
    cout<<ans[0]<<" "<<ans[1];
}
