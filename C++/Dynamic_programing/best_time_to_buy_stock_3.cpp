// Created by jishu on 23-03-2026.
//best time to buy stock 3
#include<iostream>
#include <vector>
using namespace std;
//bruteforce approach
// int find(int trans,int buy,vector<int>&arr,int index,int n) {
//     if (trans==0||index==n)
//         return 0;
//     if (buy) {
//         //two options buy karu ya nahi
//         return max(-arr[index]+find(trans,0,arr,index+1,n),find(trans,1,arr,index+1,n));
//     }
//     else {
//         //sell karu na nahi
//         return max(arr[index]+find(trans-1,1,arr,index+1,n),find(trans,0,arr,index+1,n));
//     }
// }
//top down approach
// int find(int trans,int buy,vector<int>&arr,int index,int n,vector<vector<vector<int>>>&dp) {
//     if (trans==0||index==n)
//         return 0;
//     if (dp[index][trans][buy]!=-1)
//         return dp[index][trans][buy];
//     if (buy) {
//         return dp[index][trans][buy]=max(-arr[index]+find(trans,0,arr,index+1,n,dp),find(trans,1,arr,index+1,n,dp));
//     }
//     else {
//         return dp[index][trans][buy]=max(arr[index]+find(trans-1,1,arr,index+1,n,dp),find(trans,0,arr,index+1,n,dp));
//     }
// }
int find(int trans,int buy,vector<int>&arr,int index,int n,vector<vector<vector<int>>>&dp) {
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=1;j++) {
            dp[i][0][j]=0;
        }
    }
    for (int i=0;i<=2;i++) {
        for (int j=0;j<=1;j++) {
            dp[n][i][j]=0;
        }
    }
    for (int i=n-1;i>=0;i--) {
        for (int j=1;j<=2;j++) {
            for (int k=0;k<=1;k++) {
                if (k) {
                    dp[i][j][k]=max(-arr[i]+dp[i+1][j][k-1],dp[i+1][j][k]);
                }
                else {
                    dp[i][j][k]=max(arr[i]+dp[i+1][j-1][k+1],dp[i+1][j][k]);
                }
            }
        }
    }
    //last interprited
    return dp[0][2][1];
}
int buysell(vector<int>&arr) {
    int n=arr.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2)));
    return find(2,1,arr,0,n,dp);
}
int main() {
    vector<int>arr={3,3,5,0,0,3,1,4};
    cout<<buysell(arr);
}
