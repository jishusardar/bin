//
// Created by jishu on 06-10-2025.
//Find The path Exist or not
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int rows[4]={-1,1,0,0};
int colms[4]={0,0,-1,1};
bool valid(int i,int j,int n) {
    return i>=0&&j>=0&&i<n&&j<n;
}
bool finds(int i,int j,vector<vector<int>>&grid) {
    if (grid[i][j]==2)
        return 1;
    grid[i][j]=0;
    for (int k=0;k<4;k++) {
        if (valid(i+rows[k],j+colms[k],grid.size())&&grid[i+rows[k]][j+colms[k]]!=0){
            if (finds(i+rows[k],j+colms[k],grid))
                return 1;
        }
    }
    return 0;
}
bool is_possible(vector<vector<int>>grid) {
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid.size();j++) {
            if (grid[i][j]==1) {
                return finds(i,j,grid);
            }
        }
    }
}
int main() {
    vector<vector<vector<int>>>grids={{{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}},{{1,3},{3,2}}};
    for (int i=0;i<2;i++) {
        if (is_possible(grids[i]))
            cout<<"The Path is Possible"<<endl;
        else
            cout<<"The path is Not Possible"<<endl;
    }
}