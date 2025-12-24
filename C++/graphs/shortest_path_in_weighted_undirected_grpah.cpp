//
// Created by jishu on 24-09-2025.
//sjortest path in weighted undirected graph
#include <algorithm>
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> Shortest_path(int n,int m,vector<vector<int>>&edges) {
    if (!m)
        return {-1};
    vector<vector<pair<int,int>>>Adj(n);
    for (int i=0;i<m;i++) {
        Adj[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});
        Adj[edges[i][1]-1].push_back({edges[i][0]-1,edges[i][2]});
    }
    vector<bool>visited(n,0);
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);
    dist[0]=0;
    n--;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({dist[0],0});
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
                parent[u]=node;
                dist[u]=dist[node]+weight;
                q.push({dist[u],u});
            }
        }
    }
    if (parent[n]==-1)
        return {-1};
    int index=n;
    vector<int>ans;
    while (index!=-1) {
        ans.push_back(index+1);
        index=parent[index];
    }
    ans.push_back(dist[n]);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    vector<int>Vertex={5,2,2};
    vector<int>Edges={6,1,0};
    vector<vector<vector<int>>>edges={{{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}},{{1,2,2}},{{}}};
    for (int i=0;i<3;i++) {
        vector<int>ans=Shortest_path(Vertex[i],Edges[i],edges[i]);
        for (int j=0;j<ans.size();j++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
