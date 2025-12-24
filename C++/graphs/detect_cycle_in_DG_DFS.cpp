//
// Created by jishu on 10-09-2025.
//detect cycle in Directed Graph using DFS
#include<iostream>
#include <vector>
using namespace std;
bool Detect(vector<vector<int>>&Adj,int v,vector<bool>&visited,vector<bool>&paths) {
    visited[v]=1;
    paths[v]=1;
    for (int i=0;i<Adj[v].size();i++) {
        if (paths[Adj[v][i]])
            return 1;
        if (!visited[Adj[v][i]]&&Detect(Adj,Adj[v][i],visited,paths))
            return 1;
    }
    paths[v]=0;
    return 0;
}
bool isCyclic(vector<vector<int>>&edges,int v) {
    vector<vector<int>>Adj(v);
    for (int i=0;i<edges.size();i++) {
        Adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool>visited(v,0),paths(v,0);
    for (int i=0;i<v;i++) {
        if (!visited[i]&&Detect(Adj,i,visited,paths))
            return 1;
    }
    return 0;
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
    if (isCyclic(edges,v))
        cout<<"The Graph is Cyclic";
    else
        cout<<"The Graph is Non Cyclic";
}
