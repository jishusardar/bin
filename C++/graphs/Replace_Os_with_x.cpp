//
// Created by jishu on 17-09-2025.
//Replace o's with X
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int m;
int rows[4]={-1,1,0,0};
int colms[4]={0,0,-1,1};
bool valid(int i,int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}
vector<vector<char>> fill_grid(vector<vector<char>>&mat) {
    queue<pair<int,int>>q;
    n=mat.size();
    m=mat[0].size();
    for (int i=0;i<n;i++) {
        if (mat[i][0]=='O')
            q.push(make_pair(i,0));
    }
    for (int i=1;i<m;i++) {
        if (mat[n-1][i]=='O')
            q.push(make_pair(n-1,i));
    }
    for (int i=1;i<m;i++) {
        if (mat[0][i]=='O')
            q.push(make_pair(0,i));
    }
    for (int i=1;i<n;i++) {
        if (mat[i][m-1]=='O')
            q.push(make_pair(i,m-1));
    }
    while (!q.empty()) {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        mat[i][j]='V';
        for (int k=0;k<4;k++) {
            if (valid(i+rows[k],j+colms[k])&&mat[i+rows[k]][j+colms[k]]=='O') {
                mat[i+rows[k]][j+colms[k]]='V';
                q.push(make_pair(i+rows[k],j+colms[k]));
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (mat[i][j]=='V')
                mat[i][j]='O';
            else
                mat[i][j]='X';
        }
    }
    return mat;
}
int main() {
    int n,m;
    cout<<"Entre The Rows and Colms: ";
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    vector<vector<char>>mat=fill_grid(arr);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
