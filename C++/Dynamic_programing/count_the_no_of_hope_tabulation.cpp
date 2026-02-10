//
// Created by jishu on 31-01-2026.
//count_the_no_of_hope tabulation
#include<iostream>
#include <vector>
using namespace std;
int no_of_hopes(int n) {
    vector<int>dp(n+3,-1);
    dp[n+2]=0;
    dp[n+1]=0;
    dp[n]=1;
    for (int i=n-1;i>=0;i--) {
        dp[i]=dp[i+1]+dp[i+2]+dp[i+3];
    }
    return dp[0];
}
int main() {
    int n;
    cin>>n;
    cout<<no_of_hopes(n);
}
