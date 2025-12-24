//
// Created by jishu on 10-09-2025.
//topological sort using Breadth first search or kahn algorithm
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> topologicalsort(int v,vector<vector<int>>&edges) {
    vector<vector<int>>Adj(v);
    for (int i=0;i<edges.size();i++)
        Adj[edges[i][0]].push_back(edges[i][1]);
    vector<int>indeg(v,0);
    for (int i=0;i<Adj.size();i++)
        for (int j=0;j<Adj[i].size();j++)
            indeg[Adj[i][j]]++;
    queue<int>q;
    for (int i=0;i<v;i++) {
        if (indeg[i]==0)
            q.push(i);
    }
    vector<int>ans;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for (int i=0;i<Adj[node].size();i++) {
            indeg[Adj[node][i]]--;
            if (indeg[Adj[node][i]]==0)
                q.push(Adj[node][i]);
        }
    }
    return ans;
}
int main() {
    int v,e;
    cout<<"Entre The Vertex: ";
    cin>>v;
    cout<<"Entre The Edges: ";
    cin>>e;
    vector<vector<int>>edges(e,vector<int>(2));
    for (int i=0;i<e;i++) {
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<int>ans=topologicalsort(v,edges);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}