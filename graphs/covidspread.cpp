//
// Created by jishu on 17-09-2025.
//covid spread problem
//find the time unit when all the patients are infected with covid
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int m;
int rows[4]={0,0,-1,1};
int colms[4]={-1,1,0,0};
bool valid(int i,int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}
int total_time_needed(vector<vector<int>>&hospital) {
    queue<pair<int,int>>q;
    int count=0;
    n=hospital.size();
    m=hospital[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (hospital[i][j]==2)
                q.push({i,j});
        }
    }
    while (!q.empty()) {
        int size=q.size();
        count++;
        while (size--) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (int k=0;k<4;k++) {
                if (valid(i+rows[k],j+colms[k])&&hospital[i+rows[k]][j+colms[k]]==1) {
                    hospital[i+rows[k]][j+colms[k]]=2;
                    q.push({i+rows[k],j+colms[k]});
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (hospital[i][j]==1)
                return -1;
        }
    }
    return count>0?count-1:0;
}
int main() {
    int n,m;
    cout<<"Entre The Rows and Colms: ";
    cin>>n>>m;
    vector<vector<int>>Arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++)
            cin>>Arr[i][j];
    }
    cout<<"The Total Time Needed to Spread Covid: "<<total_time_needed(Arr);
}
