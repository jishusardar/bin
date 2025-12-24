//
// Created by jishu on 11-09-2025.
//detect A Graph is Bipartite Graph or Not using BFS
#include<iostream>
#include <queue>
#include <vector>
#include <ext/concurrence.h>
using namespace std;
bool Detect(vector<vector<int>>&Adj,vector<int>&color,int v) {
    queue<int>q;
    q.push(v);
    color[v]=0;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        for (int i=0;i<Adj[node].size();i++) {
            if (color[Adj[node][i]]==-1) {
                color[Adj[node][i]]=!color[node];
                q.push(Adj[node][i]);
            }
            if (color[node]==color[Adj[node][i]])
                return 0;
        }
    }
    return 1;
}
bool isBipartite(vector<vector<int>>&Edges,int v) {
    vector<vector<int>>Adj(v);
    for (int i=0;i<Edges.size();i++) {
        Adj[Edges[i][0]].push_back(Edges[i][1]);
        Adj[Edges[i][1]].push_back(Edges[i][0]);
    }
    vector<int>color(v,-1);
    for (int i=0;i<v;i++) {
        if (color[i]==-1) {
            if (!Detect(Adj,color,i))
                return 0;
        }
    }
    return 1;
}
int main() {
    int v,e;
    cout<<"Entre The Vertex: ";
    cin>>v;
    cout<<"Entre The Edges: ";
    cin>>e;
    vector<vector<int>>edges(e,vector<int>(2));
    for (int i=0;i<edges.size();i++) {
        cin>>edges[i][0]>>edges[i][1];
    }
    if (isBipartite(edges,v))
        cout<<"The Graph is Bipartite";
    else
        cout<<"The graph is Not Bipartite";
}
