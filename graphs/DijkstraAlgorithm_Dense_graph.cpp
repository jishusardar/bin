//
// Created by jishu on 23-09-2025.
//Dijkstra Algorithm
#include<iostream>
#include <vector>
using namespace std;
vector<int> DijkstraAlgo(int n,vector<vector<int>>&edges,int src) {
    vector<vector<pair<int,int>>>Adj(n);
    for (int i=0;i<edges.size();i++) {
        Adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        Adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<bool>visited(n,0);
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    int count=n;
    while (count--) {
        int index=-1,value=INT_MAX;
        for (int j=0;j<n;j++) {
            if (!visited[j]&&dist[j]<value) {
                index=j;
                value=dist[j];
            }
        }
        visited[index]=1;
        for (int j=0;j<Adj[index].size();j++) {
            int u=Adj[index][j].first;
            int weight=Adj[index][j].second;
            if (!visited[u]&&dist[u]>dist[index]+weight) {
                dist[u]=dist[index]+weight;
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
        vector<int>ans=DijkstraAlgo(vertex[i],NoofEdges[i],Source[i]);
        for (int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
