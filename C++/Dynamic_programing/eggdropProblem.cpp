//
// Created by jishu on 27-03-2026.
//Egg Drop Problem
#include<iostream>
#include <vector>
using namespace std;
//bruteforce approach
// int find(int eggs,int floors) {
//     if (eggs==1)
//         return floors;
//     if (floors==0)
//         return 0;
//     int ans=INT_MAX;
//     int temp;
//     for (int i=1;i<=floors;i++) {
//         temp=1+max(find(eggs-1,i-1),find(eggs,floors-i));
//         ans=min(ans,temp);
//     }
//     return ans;
// }
// int eggDrop(int n,int k) {
//     return find(n,k);
// }
//top down approach
// int find(int eggs,int floors,vector<vector<int>>&dp) {
//     if (eggs==1)
//         return floors;
//     if (floors==0)
//         return 0;
//     if (dp[eggs][floors]!=-1)
//         return dp[eggs][floors];
//     int ans=INT_MAX;
//     int temp;
//     for (int i=1;i<=floors;i++) {
//         temp=1+max(find(eggs-1,i-1,dp),find(eggs,floors-i,dp));
//         ans=min(ans,temp);
//     }
//     return ans;
// }
// int eggDrop(int n,int k) {
//     vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
//     return find(n,k,dp);
// }
//bottom up approach
int eggDrop(int n,int k) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for (int j=0;j<=k;j++) {
        dp[1][j]=j;
    }
    for (int i=0;i<=n;i++) {
        dp[i][0]=1;
    }
    for (int i=2;i<=n;i++) {
        for (int j=2;j<=k;j++) {
            int ans=INT_MAX;
            int temp;
            for (int a=1;a<=j;a++) {
                temp=1+max(dp[i-1][a-1],dp[i][j-a]);
                ans=min(ans,temp);
            }
            dp[i][j]=ans;
        }
    }
    return dp[n][k];
}
int main() {
    int n,k;
    cin>>n>>k;
    cout<<eggDrop(n,k);
}
