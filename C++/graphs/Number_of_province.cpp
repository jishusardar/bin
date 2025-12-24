//
// Created by jishu on 17-09-2025.
//Number Of provience
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int m;
int number_of_province(vector<vector<int>>&adj) {
    n=adj.size();
    m=adj.size();
    int count=0;
    queue<pair<int,int>>q;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (adj[i][j]==1) {
                q.push(make_pair(i,j));
                count++;
                adj[i][j]=0;
                while (!q.empty()) {
                    int ni=q.front().first;
                    int nj=q.front().second;
                    q.pop();
                    for (int k=0;k<m;k++) {
                        if (adj[ni][k]==1) {
                            adj[ni][k]=0;
                            q.push(make_pair(k,ni));
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
    cout<<"Entre The Rows and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"The Number Of Provinces is: "<<number_of_province(arr);
}
