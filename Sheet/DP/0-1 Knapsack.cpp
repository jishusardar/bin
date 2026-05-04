//
// Created by jishu on 03-05-2026.
//0-1 knapsack
#include<iostream>
#include<vector>
using namespace std;
//bruteforce approach
// int find(int n,vector<int>&values,vector<int>&weights,int capacity) {
//     if (capacity==0)
//         return 0;
//     if (n==0)
//         return 0;
//     if (weights[n-1]>capacity)
//         return find(n-1,values,weights,capacity);
//     return max(values[n-1]+find(n-1,values,weights,capacity-weights[n-1]),find(n-1,values,weights,capacity));
// }
//top down approach
// int find(int n,vector<int>&values,vector<int>&weight,int capacity,vector<vector<int>>&dp) {
//     if (capacity==0)
//         return 0;
//     if (n==0)
//         return 0;
//     if (dp[n][capacity]!=-1)
//         return dp[n][capacity];
//     if (weight[n-1]>capacity)
//         return dp[n][capacity]=find(n-1,values,weight,capacity,dp);
//     else
//     return dp[n][capacity]=max(values[n-1]+find(n-1,values,weight,capacity-weight[n-1],dp),find(n-1,values,weight,capacity,dp));
// }
//bottom up approach
int solve(vector<int> &values, vector<int> &weight, int capacity) {
    int n=values.size();
    // return find(n,values,weight,capacity);
    // vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
    // return find(n,values,weight,capacity,dp);
    //bottom up approach
    // vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=capacity;j++) {
    //         if (weight[i-1]>j)
    //             dp[i][j]=dp[i-1][j];
    //         else
    //             dp[i][j]=max(values[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
    //     }
    // }
    // return dp[n][capacity];
    //reduced space complexity
    vector<int>dp(capacity+1,0);
    vector<int>temp(capacity+1);
    temp=dp;
    for (int i=1;i<=n;i++) {
        for (int j=weight[i-1];j<=capacity;j++) {
            dp[j]=max(values[i-1]+temp[j-weight[i-1]],temp[j]);
        }
        temp=dp;
    }
    return dp[capacity];
}
int main() {
    int n,c;
    cout<<"Entre The Size and capacity:  ";
    cin>>n>>c;
    cout<<"Entre The Values: ";
    vector<int>val(n);
    for (int i=0;i<n;i++)
        cin>>val[i];
    cout<<"Entre The Weights: ";
    vector<int>weight(n);
    for (int i=0;i<n;i++)
        cin>>weight[i];
    cout<<solve(val,weight,c);
}
