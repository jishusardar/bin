//
// Created by jishu on 17-09-2025.
//Rotten Oranges
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
int time_needed(vector<vector<int>>&mat) {
    queue<pair<int,int>>q;
    n=mat.size();
    m=mat[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (mat[i][j]==2)
                q.push(make_pair(i,j));
        }
    }
    int count=0;
    while (!q.empty()) {
        int size=q.size();
        count++;
        while (size--) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (int k=0;k<4;k++) {
                if (valid(i+rows[k],j+colms[k])&&mat[i+rows[k]][j+colms[k]]==1) {
                    mat[i+rows[k]][j+colms[k]]=2;
                    q.push(make_pair(i+rows[k],j+colms[k]));
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (mat[i][j]==1)
                return -1;
        }
    }
    return count>0?count-1:0;
}
int main() {
    int n,m;
    cout<<"Entre The Rows and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"The Total Time Needed For To Rotten Oranges: "<<time_needed(arr);
}
