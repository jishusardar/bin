//
// Created by jishu on 30-01-2026.
//climbing nth stairs bottom up approach
#include<iostream>
#include <vector>
using namespace std;
int Nclimbingstairs(int stair,int n,vector<int>&dp) {
    if (stair==n)
        return 1;
    if (stair>n)
        return 0;
    if (dp[stair]!=-1)
        return dp[stair];
    dp[stair]=Nclimbingstairs(stair+1,n,dp)+Nclimbingstairs(stair+2,n,dp);
    return dp[stair];
}
int main() {
    int n;
    cin>>n;
    vector<int>dp(n+2,-1);
    cout<<Nclimbingstairs(0,n,dp);
}
