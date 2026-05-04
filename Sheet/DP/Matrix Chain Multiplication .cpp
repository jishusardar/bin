// Created by jishu on 04-05-2026.
//
#include<iostream>
#include <vector>
using namespace std;
//bruteforce
// int find(int start,int end,vector<int>&arr) {
//     if (start+1==end)
//         return 0;
//     int ans=INT_MAX;
//     for (int mid=start+1;mid<end;mid++) {
//         int temp=find(start,mid,arr)+find(mid,end,arr)+arr[start]*arr[mid]*arr[end];
//         ans=min(ans,temp);
//     }
//     return ans;
// }
//top down approach
int find(int start,int end,vector<int>&arr,vector<vector<int>>&dp) {
    if (start+1==end)
        return 0;
    if (dp[start][end]!=-1)
        return dp[start][end];
    int ans=INT_MAX;
    for (int k=start+1;k<end;k++) {
        int temp=find(start,k,arr,dp)+find(k,end,arr,dp)+arr[start]*arr[k]*arr[end];
        ans=min(ans,temp);
    }
    return dp[start][end]=ans;
}
int matrixMultiplication(vector<int> &arr) {
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return find(0,n-1,arr,dp);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<matrixMultiplication(arr);
}
