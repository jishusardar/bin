//
// Created by jishu on 31-01-2026.
//bottom to up approach
#include<iostream>
#include <vector>
using namespace std;
int fibonachii(int n) {
    if (n<=1)
        return n;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    cout<<fibonachii(n);
}