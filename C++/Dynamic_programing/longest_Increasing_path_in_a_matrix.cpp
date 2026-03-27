//
// Created by jishu on 28-03-2026.
//longest increasing path in a matrix
#include<iostream>
#include <vector>
using namespace std;
bool check(int i,int j,int n,int m) {
    return i<n&&i>=0&&j<m&&j>=0;
}
int rows[4]={1,-1,0,0};
int colm[4]={0,0,-1,1};
void DFS(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&paths,int n,int m) {
    paths[i][j]=1;
    for (int k=0;k<4;k++) {
        if (check(i+rows[k],j+colm[k],n,m)&&matrix[i+rows[k]][j+colm[k]]>matrix[i][j]) {
            if (!paths[i+rows[k]][j+colm[k]])
                DFS(i+rows[k],j+colm[k],matrix,paths,n,m);
            paths[i][j]=max(paths[i][j],1+paths[i+rows[k]][j+colm[k]]);
        }
    }
}
int longestIncreasingPath(vector<vector<int>>&matrix,int n,int m) {
    vector<vector<int>>paths(n,vector<int>(m,0));
    int total=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!paths[i][j])
                DFS(i,j,matrix,paths,n,m);
            total=max(total,paths[i][j]);
        }
    }
    return total;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for (int i=0;i<n;i++){
        cout<<"Entre The Row: ";
        for (int j=0;j<m;j++)
            cin>>matrix[i][j];
    }

    cout<<longestIncreasingPath(matrix,n,m);
}
