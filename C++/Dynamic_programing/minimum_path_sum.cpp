//
// Created by jishu on 22-03-2026.
//minimum path sum
#include<iostream>
#include <vector>
using namespace std;
int minimum_path_sum(vector<vector<int>>&grid) {
    int n=grid.size(),m=grid[0].size();
    for (int i=n-2;i>=0;i--) {
        grid[i][m-1]+=grid[i+1][m-1];
    }
    for (int i=m-2;i>=0;i--) {
        grid[n-1][i]+=grid[n-1][i+1];
    }
    for (int i=n-2;i>=0;i--) {
        for (int j=m-2;j>=0;j--) {
            grid[i][j]+=min(grid[i+1][j],grid[i][j+1]);
        }
    }
    return grid[0][0];
}
int main() {
    vector<vector<vector<int>>>grid={{{1,3,1},{1,5,1},{4,2,1}},{{1,2,3},{4,5,6}}};
    cout<<minimum_path_sum(grid[0])<<" "<<minimum_path_sum(grid[1]);
}