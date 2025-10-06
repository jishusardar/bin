//
// Created by jishu on 06-10-2025.
//Shortest Source to Destination Path
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int rows[4]={-1,1,0,0};
int colms[4]={0,0,-1,1};
bool valid(int i,int j,int n,int m) {
    return i>=0&&j>=0&&i<n&&j<m;
}
int Shorteststeps(int n,int m,vector<vector<int>>grid,int x,int y) {
    if (!grid[0][0])
        return -1;
    if (x==0&&y==0)
        return 0;
    queue<pair<int,int>>q;
    grid[0][0]=0;
    q.push({0,0});
    int step=0;
    while (!q.empty()) {
        int size=q.size();
        while (size--) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (int k=0;k<4;k++) {
                if (valid(i+rows[k],j+colms[k],n,m)&&grid[i+rows[k]][j+colms[k]]) {
                    if (i+rows[k]==x&&j+colms[k]==y)
                        return step+1;
                    grid[i+rows[k]][j+colms[k]]=0;
                    q.push({i+rows[k],j+colms[k]});
                }
            }
        }
        step++;
    }
    return -1;
}
int main() {
    vector<int>Ns={3,3};
    vector<int>Ms={4,4};
    vector<vector<vector<int>>>Matrixs={{{1,0,0,0},{1,1,0,1},{0,1,1,1}},{{1,1,1,1},{0,0,0,1},{0,0,0,1}}};
    vector<int>Xs={2,0};
    vector<int>Ys={3,3};
    cout<<"The Shortest Paths: ";
    for (int i=0;i<2;i++) {
        cout<<Shorteststeps(Ns[i],Ms[i],Matrixs[i],Xs[i],Ys[i])<<" ";
    }
}