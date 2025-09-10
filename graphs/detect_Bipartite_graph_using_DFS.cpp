//
// Created by jishu on 11-09-2025.
//Detect Bipartite Graph using DFS
#include<iostream>
#include <vector>
using namespace std;
bool Detect(vector<vector<int>>&Adj,vector<int>&color,int v) {
    for (int i=0;i<Adj[v].size();i++) {
        if (color[Adj[v][i]]==-1) {
            color[Adj[v][i]]=!color[v];
            if (!Detect(Adj,color,Adj[v][i]))
                return 0;
        }
        if (color[Adj[v][i]]==color[v])
            return 0;
    }
    return 1;
}
bool isBipartite(vector<vector<int>>&edges,int v) {
    vector<vector<int>>Adj(v);
    for (int i=0;i<edges.size();i++) {
        Adj[edges[i][0]].push_back(edges[i][1]);
        Adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int>color(v,-1);
    color[0]=0;
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
    for (int i=0;i<edges.size();i++)
        cin>>edges[i][0]>>edges[i][1];
    if (isBipartite(edges,v))
        cout<<"This is Bipartite graph";
    else
        cout<<"This is Not Bipartite graph";
}
