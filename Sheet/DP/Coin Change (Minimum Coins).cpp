// Created by jishu on 30-04-2026.
//coin change
#include<iostream>
#include <vector>
using namespace std;
// int find(int n,int sum,vector<int>&coins,int &ans,int ncoin,vector<vector<vector<int>>>&dp){
//     if(sum==0){
//         ans=min(ans,ncoin);
//         return 1;
//     }
//     if(n==0)
//         return 0;
//     if(dp[n][sum][ncoin]!=-1)
//         return dp[n][sum][ncoin];
//     if(coins[n-1]>sum)
//         return dp[n][sum][ncoin]=find(n-1,sum,coins,ans,ncoin,dp);
//     else
//         return dp[n][sum][ncoin]=find(n,sum-coins[n-1],coins,ans,ncoin+1,dp)+find(n-1,sum,coins,ans,ncoin,dp);
// }
// int find(int n,int sum,vector<int>&coins,int &ans,int ncoin) {
//     if (sum==0) {
//         ans=min(ans,ncoin);
//         return 1;
//     }
//     if (n==0)
//         return 0;
//     if (coins[n-1]>sum)
//         return find(n-1,sum,coins,ans,ncoin);
//     else
//         return find(n,sum-coins[n-1],coins,ans,ncoin+1)+find(n-1,sum,coins,ans,ncoin);
// }
//another bruteforce approach
// int find(int sum,vector<int>&coins) {
//     if (sum==0)
//         return 0;
//     if (sum<0)
//         return INT_MAX;
//     int mincoins=INT_MAX;
//     for (int i=0;i<coins.size();i++) {
//         int temp=find(sum-coins[i],coins);
//         if (temp!=INT_MAX)
//             mincoins=min(mincoins,temp+1);
//     }
//     return mincoins;
// }
//top down approach
// int find(int sum,vector<int>&coins,vector<int>&dp) {
//     if (sum==0)
//         return 0;
//     if (sum<0)
//         return INT_MAX;
//     if (dp[sum]!=-1)
//         return dp[sum];
//     int mincoins=INT_MAX;
//     for (int i=0;i<coins.size();i++) {
//         int temp=find(sum-coins[i],coins,dp);
//         if (temp!=INT_MAX)
//             mincoins=min(mincoins,temp+1);
//     }
//     return dp[sum]=mincoins;
// }
int minCoins(vector<int> &coins, int sum) {
    // int n=coins.size();
    // int ans=INT_MAX;
    //find(n,sum,coins,ans,0);
    //vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(sum+1,vector<int>(sum+1,-1)));
    // find(n,sum,coins,ans,0,dp);
    // return ans==INT_MAX?-1:ans;
    if (sum==0)
        return 0;
    // int ans=find(sum,coins);
    // return ans==INT_MAX?-1:ans;
    vector<int>dp(sum+1);
    // int ans=find(sum,coins,dp);
    // return ans==INT_MAX?-1:ans;
    dp[0]=0;
    int minCoins=INT_MAX;
    for (int j=1;j<=sum;j++) {
        for (int i=0;i<coins.size();i++) {
            int res;
            if (j-coins[i]<0)
            res=INT_MAX;
            else
            res=dp[j-coins[i]];
            if (res!=INT_MAX)
                minCoins=min(minCoins,res+1);
        }
    }
    return minCoins;
}
int main() {
    int n,sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<minCoins(arr,sum);
}
