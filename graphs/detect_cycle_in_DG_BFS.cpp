//
// Created by jishu on 10-09-2025.
//detect cycle in a directed graph using approach BFS kahn algorithm
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool Detect(vector<vector<int>>&Adj,int v) {
    queue<int>q;
    vector<int>indeg(v,0);
    for (int i=0;i<Adj.size();i++)
        for (int j=0;j<Adj[i].size();j++)
            indeg[Adj[i][j]]++;
    for (int i=0;i<indeg.size();i++) {
        if (!indeg[i])
            q.push(i);
    }
    if (q.empty())
        return 1;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        v--;
        for (int i=0;i<Adj[node].size();i++) {
            indeg[Adj[node][i]]--;
            if (indeg[Adj[node][i]]==0)
                q.push(Adj[node][i]);
        }
    }
    return v!=0;
}
bool isCyclic(vector<vector<int>>&edges,int v) {
    vector<vector<int>>Adj(v);
    for (int i=0;i<edges.size();i++) {
        Adj[edges[i][0]].push_back(edges[i][1]);
    }
    return Detect(Adj,v);
}
int main() {
    int v,e;
    cout<<"Entre The vertex: ";
    cin>>v;
    cout<<"Entre The Edges: ";
    cin>>e;
    vector<vector<int>>edges(e,vector<int>(2));
    for (int i=0;i<edges.size();i++)
        cin>>edges[i][0]>>edges[i][1];
    if (isCyclic(edges,v))
        cout<<"The Cycle is present";
    else
        cout<<"The Cycle is not present";
}
