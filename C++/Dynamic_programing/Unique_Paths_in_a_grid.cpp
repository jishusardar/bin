//
// Created by jishu on 21-03-2026.
//Unique Paths in a grid
#include<iostream>
#include <vector>
using namespace std;
int uniquePaths(vector<vector<int>>&grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for (int i=n-2;i>=0;i--) {
        if (!grid[i][m-1])
        dp[i][m-1]=1;
        else
            break;
    }
    for (int i=m-1;i>=0;i--) {
        if (!grid[n-1][i])
            dp[n-1][i]=1;
        else
            break;
    }
    for (int i=n-2;i>=0;i--) {
        for (int j=m-2;j>=0;j--) {
            if (!grid[i][j])
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    return dp[0][0];
}
int main() {
    vector<vector<int>>arr={{0, 0, 0},{0, 1, 0}, {0, 0, 0}};
    cout<<uniquePaths(arr);
}
