//
// Created by jishu on 19-10-2025.
//Foursum Problem
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Four_Sum(vector<int>&arr,int sum) {
    sort(arr.begin(),arr.end());
    vector<int>ans(4,-1);
    for (int i=0;i<arr.size()-3;i++) {
        for (int j=i+1;j<arr.size()-2;j++) {
            int target=sum-arr[i]-arr[j];
            int start=j+1,end=arr.size()-1;
            while (start<end) {
                if (arr[start]==target-arr[end]) {
                    ans[0]=arr[i];
                    ans[1]=arr[j];
                    ans[2]=arr[start];
                    ans[3]=arr[end];
                    return ans;
                }
                else if (arr[start]>target-arr[end])
                    end--;
                else
                    start++;
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
    vector<int>ans=Four_Sum(arr,sum);
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3];
}
