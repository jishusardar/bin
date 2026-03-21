//
// Created by jishu on 21-03-2026.
//Number of unique paths in a grid
#include<iostream>
#include <vector>
using namespace std;
// int numberOfUniquePaths(int a,int b) {
//     vector<vector<int>>dp(a,vector<int>(b,1));
//     for (int i=a-2;i>=0;i--)
//         for (int j=b-2;j>=0;j--)
//             dp[i][j]=dp[i+1][j]+dp[i][j+1];
//     return dp[0][0];
// }
int numberOfUniquePaths(int a,int b) {
    vector<int>dp(b,1);
    for (int i=a-2;i>=0;i--)
        for (int j=b-2;j>=0;j--) {
            int pre=dp[j];
            dp[j]=pre+dp[j+1];
        }
    return dp[0];
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<numberOfUniquePaths(a,b);
}