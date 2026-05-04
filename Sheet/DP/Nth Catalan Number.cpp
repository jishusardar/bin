//
// Created by jishu on 04-05-2026.
//
#include<iostream>
#include <vector>
using namespace std;
//bruteforce approach
int find(int i,int j,int n) {
    if (i+j==2*n)
        return 1;
    int ans=0;
    if (i<n)
        ans+=find(i+1,j,n);
    if (j<i)
        ans+=find(i,j+1,n);
    return ans;
}
//top down approach
int find(int i,int j,int n,vector<vector<int>>&dp) {
    if (i+j==2*n)
        return 1;
    int ans=0;
    if (dp[i][j]!=-1)
        return dp[i][j];
    if (i<n)
        ans+=find(i+1,j,n,dp);
    if (j<i)
        ans+=find(i,j+1,n,dp);
    return dp[i][j]=ans;
}
int findCatalan(int n) {
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return find(0,0,n,dp);
}
int main() {
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    cout<<findCatalan(n);
}
