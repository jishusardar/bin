//
// Created by jishu on 09-09-2025.
//detect cycle in undirected graph using DFS
//may be disconnected graph
#include<iostream>
#include <vector>
using namespace std;
bool detect(vector<vector<int>>&Adj,int v,int parent,vector<bool>&visited) {
    visited[v]=1;
    for (int i=0;i<Adj[v].size();i++) {
        if (Adj[v][i]==parent)
            continue;
        if (visited[Adj[v][i]])
            return 1;
        if (detect(Adj,Adj[v][i],v,visited))
            return 1;
    }
    return 0;
}
bool isCycle(vector<vector<int>>Adjmat,int v) {
    vector<bool>visited(v,0);
    for (int i=0;i<v;i++) {
        if (!visited[i]&&detect(Adjmat,i,-1,visited))
            return 1;
    }
    return 0;
}
int main() {
    int v,e;
    cout<<"Entre The no. of Vertex: ";
    cin>>v;
    cout<<"Entre The no of Edges: ";
    cin>>e;
    vector<vector<int>>edges(e,vector<int>(2));
    for (int i=0;i<edges.size();i++) {
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>Adjmat(v);
    for (int i=0;i<edges.size();i++) {
        Adjmat[edges[i][0]].push_back(edges[i][1]);
        Adjmat[edges[i][1]].push_back(edges[i][0]);
    }
    if (isCycle(Adjmat,Adjmat.size()))
        cout<<"Cycle is present";
    else
        cout<<"Cycle is not present";

}
