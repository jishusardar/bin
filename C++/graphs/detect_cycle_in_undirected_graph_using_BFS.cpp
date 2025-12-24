//
// Created by jishu on 09-09-2025.
//The graph may contain disconnected Graph
//Detect Cycle in undirected graph using BFS
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
bool detect(vector<vector<int>>Adjmat,vector<bool>&visited,int v) {
    queue<pair<int,int>>q;
    q.push({v,-1});
    while (!q.empty()) {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for (int i=0;i<Adjmat[node].size();i++) {
            if (Adjmat[node][i]==parent)
                continue;
            if (visited[Adjmat[node][i]])
                return 1;
            visited[Adjmat[node][i]]=1;
            q.push({Adjmat[node][i],node});
        }
    }
    return 0;
}
bool isCycle(vector<vector<int>>Adj,int v) {
    vector<bool>visited(v,0);
    for (int i=0;i<Adj.size();i++) {
        if (!visited[i]&&detect(Adj,visited,i))
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
    vector<vector<int>>Adjmat(v);
    for (int i=0;i<edges.size();i++) {
        Adjmat[edges[i][0]].push_back(edges[i][1]);
        Adjmat[edges[i][1]].push_back(edges[i][0]);
    }
    if (isCycle(Adjmat,v))
        cout<<"The Cycle is present";
    else
        cout<<"The Cycle is not present";
}
