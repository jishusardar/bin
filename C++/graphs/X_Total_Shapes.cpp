//
// Created by jishu on 17-09-2025.
//X Total Shapes
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int rows[4]={-1,1,0,0};
int colms[4]={0,0,-1,1};
int n;
int m;
bool valid(int i,int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}
int total_x_group(vector<vector<char>>&grid) {
    queue<pair<int,int>>q;
    int count=0;
    n=grid.size();
    m=grid[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j]=='X') {
                q.push(make_pair(i,j));
                count++;
                grid[i][j]='O';
                while (!q.empty()) {
                    int ni=q.front().first;
                    int nj=q.front().second;
                    q.pop();
                    for (int k=0;k<4;k++) {
                        if (valid(ni+rows[k],nj+colms[k])&&grid[ni+rows[k]][nj+colms[k]]=='X') {
                            grid[ni+rows[k]][nj+colms[k]]='O';
                            q.push(make_pair(i+rows[k],j+colms[k]));
                        }
                    }
                }
            }
        }
    }
    return count;
}
int main() {
    int n,m;
    cout<<"Entre The rows and Colms: ";
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    cout<<"The Total group of X is : "<<total_x_group(arr);
}
