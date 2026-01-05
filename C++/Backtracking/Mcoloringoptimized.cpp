//
// Created by jishu on 05-01-2026.
//Mcoloring Optimized
#include<iostream>
#include <vector>
using namespace std;
bool isPossible(int node,vector<vector<bool>>&graph,int m,int v,vector<int>&color) {
    if (node==v)
        return 1;
    for (int i=0;i<m;i++) {
        bool poss=1;
        for (int j=0;j<v;j++) {
            if (graph[node][j]&&color[j]==i) {
                poss=0;
                break;
            }
        }
        if (poss) {
            color[node]=i;
            if (isPossible(node+1,graph,m,v,color))
                return 1;
            color[node]=-1;
        }
    }
    return 0;
}
bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    vector<vector<bool>>graph(v,vector<bool>(v,0));
    for (int i=0;i<edges.size();i++) {
        graph[edges[i][0]][edges[i][1]]=1;
        graph[edges[i][1]][edges[i][0]]=1;
    }
    vector<int>color(v,-1);
    return isPossible(0,graph,m,v,color);
}
int main() {
    vector<int>vs={4,3};
    vector<int>ms={3,2};
    vector<vector<vector<int>>>edges={{{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}},{{0, 1}, {1, 2}, {0, 2}}};
    for (int i=0;i<vs.size();i++) {
        if (graphColoring(vs[i],edges[i],ms[i]))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
}
