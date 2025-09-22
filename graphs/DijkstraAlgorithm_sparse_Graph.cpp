//
// Created by jishu on 23-09-2025.
//Dijkstra Algorithm Sparse Graph
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> Dijkstra_Algorithm(int v,int src,vector<vector<int>>&edges) {
    vector<vector<pair<int,int>>>Adj(v);
    for (int i=0;i<edges.size();i++) {
        Adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        Adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<int>dist(v,INT_MAX);
    vector<bool>visited(v,0);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({dist[src],src});
    while (!q.empty()) {
        int node=q.top().second;
        q.pop();
        if (visited[node])
            continue;
        visited[node]=1;
        for (int i=0;i<Adj[node].size();i++) {
            int u=Adj[node][i].first;
            int weight=Adj[node][i].second;
            if (!visited[u]&&dist[u]>dist[node]+weight) {
                dist[u]=dist[node]+weight;
                q.push({dist[u],u});
            }
        }
    }
    return dist;
}
int main() {
    int n=2;
    vector<int>vertex={3,5};
    vector<vector<vector<int>>>NoofEdges={{{0, 1, 1}, {1, 2, 3}, {0, 2, 6}},{{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}}};
    vector<int>Source={2,0};
    for (int i=0;i<n;i++) {
        vector<int>ans=Dijkstra_Algorithm(vertex[i],Source[i],NoofEdges[i]);
        for (int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
