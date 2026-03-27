// Created by jishu on 27-03-2026.
//Best time to buy and sell stock IV
//k transaction is allowed
#include<iostream>
#include <vector>
using namespace std;
int buyandsellIV(vector<int>&prices,int k) {
    int n=prices.size();
    vector<vector<int>>dp(k+1,vector<int>(n+1,0));
    int total;
    for (int i=1;i<=k;i++) {
        total=-prices[0];
        for (int j=2;j<=n;j++) {
            dp[i][j]=max(dp[i][j-1],prices[j-1]+total);
            total=max(total,-prices[j-1]+dp[i-1][j]);
        }
    }
    return dp[k][n];
}
int main() {
    vector<int>prices={3,2,6,5,0,3};
    cout<<buyandsellIV(prices,2);
}
