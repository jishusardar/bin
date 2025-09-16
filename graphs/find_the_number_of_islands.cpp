//
// Created by jishu on 17-09-2025.
//find the number of islands
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int rows[8]={-1,1,0,0,-1,1,1,-1};
int colms[8]={0,0,-1,1,-1,1,-1,1};
bool valid(int i,int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}
int numberofislands(vector<vector<char>>&adj) {
    queue<pair<int,int>>q;
    int count=0;
    n=adj.size();
    m=adj[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (adj[i][j]=='L') {
                q.push(make_pair(i,j));
                count++;
                adj[i][j]='W';
                while (!q.empty()) {
                    int ni=q.front().first;
                    int nj=q.front().second;
                    q.pop();
                    for (int k=0;k<8;k++) {
                        if (valid(ni+rows[k],nj+colms[k])&&adj[ni+rows[k]][nj+colms[k]]=='L') {
                            adj[ni+rows[k]][nj+colms[k]]='W';
                            q.push(make_pair(ni+rows[k],nj+rows[k]));
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
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"The Number Of Islands are : "<<numberofislands(arr);
}
