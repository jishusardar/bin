//
// Created by jishu on 30-04-2026.
//coin change
#include<iostream>
#include <vector>
using namespace std;
// int find(int sum,int n,vector<int>&coins) {
//     if (sum==0)
//         return 1;
//     if (n==0)
//         return 0;
//     if (coins[n-1]>sum)
//         return find(sum,n-1,coins);
//     else
//         return find(sum-coins[n-1],n,coins)+find(sum,n-1,coins);
// }
// int find(int sum,int n,vector<int>&coins,vector<vector<int>>&dp) {
//     if (sum==0)
//         return 1;
//     if (n==0)
//         return 0;
//     if (dp[n][sum]!=-1)
//         return dp[n][sum];
//     if (coins[n-1]>sum)
//         return find(sum,n-1,coins,dp);
//     return dp[n][sum]=find(sum-coins[n-1],n,coins,dp)+find(sum,n-1,coins,dp);
// }
int count(vector<int>&coins,int sum) {
    //bruteforce
    //return find(sum,coins.size(),coins);
    //top down approach
    // int n=coins.size();
    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    // return find(sum,n,coins,dp);
    //bottom up approach
    // int n=coins.size();
    // vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    // for (int i=0;i<=n;i++) {
    //     dp[i][0]=1;
    // }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=sum;j++) {
    //         if (coins[i-1]>j)
    //             dp[i][j]=dp[i-1][j];
    //         else
    //             dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
    //     }
    // }
    // return dp[n][sum];
    //more optimized reduce the complexity
    int n=coins.size();
    vector<int>dp(sum+1,0);
        dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=coins[i-1];j<=sum;j++) {
            dp[j]=dp[j-coins[i-1]]+dp[j];
        }
    }
    return dp[sum];
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<count(arr,sum);
}