//
// Created by jishu on 19-10-2025.
//ThreeSum Problem
#include<iostream>
#include <vector>
using namespace std;
 vector<int> Three_Sum(vector<int>&arr,int sum) {
     vector<int>ans(3,-1);
    for (int i=0;i<arr.size()-2;i++) {
        for (int j=i+1;j<arr.size()-1;j++) {
            int start=j+1,end=arr.size()-1;
            int target=sum-arr[i]-arr[j];
            while (start<=end) {
                int mid=start+(end-start)/2;
                if (arr[mid]==target) {
                    ans[0]=arr[i];
                    ans[1]=arr[j];
                    ans[2]=arr[mid];
                    return ans;
                }
                else if (arr[mid]>target)
                    end=mid-1;
                else
                    start=mid+1;
            }
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
     int sum;
     cout<<"Entre The Sum: ";
     cin>>sum;
     vector<int>ans=Three_Sum(arr,sum);
     cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
}
