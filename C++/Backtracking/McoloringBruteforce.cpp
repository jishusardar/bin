//
// Created by jishu on 05-01-2026.
//M Coloring Problem
#include<iostream>
#include <vector>
#include <bits/stl_pair.h>
using namespace std;
bool coloring(int node,vector<vector<bool>>&graph,int m,int v,vector<int>&color) {
    for (int i=0;i<m;i++) {
        bool Ispos=1;
        for (int j=0;j<v;j++) {
            if (graph[node][j]&&color[j]==i) {
                Ispos=0;
                break;
            }
        }
        if (!Ispos)
            continue;
        color[node]=i;
        Ispos=1;
        for (int j=0;j<v;j++) {
            if (graph[node][j]&&color[j]==-1) {
                if (!coloring(j,graph,m,v,color)) {
                    Ispos=0;
                    break;
                }
            }
        }
        if (Ispos)
            return 1;
        color[node]=-1;
    }
    return 0;
}
bool Mcoloring(int v,vector<vector<int>> &edges, int m) {
    vector<int>color(v,-1);
    vector<vector<bool>>graph(v,vector<bool>(v,0));
    for (int i=0;i<edges.size();i++) {
        graph[edges[i][0]][edges[i][1]]=1;
        graph[edges[i][1]][edges[i][0]]=1;
    }
    return coloring(0,graph,m,v,color);
}
int main() {
    vector<int>vs={4,3};
    vector<int>ms={3,2};
    vector<vector<vector<int>>>edges={{{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}},{{0, 1}, {1, 2}, {0, 2}}};
    for (int i=0;i<vs.size();i++) {
        if (Mcoloring(vs[i],edges[i],ms[i]))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
