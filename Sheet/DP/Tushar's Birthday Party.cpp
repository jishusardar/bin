//
// Created by jishu on 03-05-2026.
//
#include<iostream>
#include <vector>
using namespace std;
//bruteforce approach
// int find(int n,vector<int>&B,vector<int>&C,int capacity) {
//     if (capacity==0)
//         return 0;
//     if (n==0)
//         return INT_MAX;
//     if (B[n-1]>capacity)
//         return find(n-1,B,C,capacity);
//     else
//         return min(C[n-1]+find(n,B,C,capacity-B[n-1]),find(n-1,B,C,capacity));
// }
// int solve(vector<int>&A,vector<int>&B,vector<int>&C) {
//     int ans=0;
//     int n=A.size();
//     for (int i=0;i<A.size();i++) {
//         int temp=find(n,B,C,A[i]);
//         if (temp!=INT_MAX)
//             ans+=temp;
//     }
//     return ans;
// }
//top down approach
// int find(int n,vector<int>&B,vector<int>&C,int capacity,vector<vector<int>>&dp) {
//     if (capacity==0)
//         return 0;
//     if (n==0)
//         return INT_MAX;
//     if (dp[n][capacity]!=-1)
//         return dp[n][capacity];
//     if (B[n-1]>capacity)
//         return dp[n][capacity]=find(n-1,B,C,capacity,dp);
//     else
//         return dp[n][capacity]=min(C[n-1]+find(n,B,C,capacity-B[n-1],dp),find(n-1,B,C,capacity,dp));
// }
//bottom up approach
// long long  find(int n,vector<int>&B,vector<int>&C,int capacity) {
//     vector<vector<long long>>dp(n+1,vector<long long>(capacity+1,INT_MAX));
//     for (int i=0;i<=n;i++) {
//         dp[i][0]=0;
//     }
//     for (int i=1;i<=n;i++) {
//         for (int j=1;j<=capacity;j++) {
//             if (B[i-1]>j)
//                 dp[i][j]=dp[i-1][j];
//             else
//                 dp[i][j]=min(C[i-1]+dp[i][j-B[i-1]],dp[i-1][j]);
//         }
//     }
//     return dp[n][capacity];
// }
long long find(int n,vector<int>&B,vector<int>&C,int capacity) {
    vector<long long>dp(capacity+1,INT_MAX);
    dp[0]=0;
    vector<long long>temp(capacity+1,INT_MAX);
    temp=dp;
    for (int i=1;i<=n;i++) {
        for (int j=B[i-1];j<=capacity;j++) {
            dp[j]=min(C[i-1]+dp[j-B[i-1]],temp[j]);
        }
        temp=dp;
    }
    return dp[capacity];
}
int solve(vector<int>&A,vector<int>&B,vector<int>&C) {
    long long  ans=0;
    int n=B.size();
    for (int i=0;i<A.size();i++) {
        long long  temp=find(n,B,C,A[i]);
        if (temp!=INT_MAX)
            ans+=temp;
    }
    return ans;
}
int main() {
    vector<int>A={4, 6};
    vector<int>B={1,3};
    vector<int>C={5,3};
    cout<<solve(A,B,C);
}