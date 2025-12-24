//
// Created by jishu on 21-09-2025.
//return the shortest path from source node to destination node
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> Shortest_paths(vector<pair<int,int>>&edges,int n,int src,int dest) {
    vector<vector<int>>Adj(n);
    for (int i=0;i<edges.size();i++) {
        Adj[edges[i].first-1].push_back(edges[i].second-1);
        Adj[edges[i].second-1].push_back(edges[i].first-1);
    }
    src--;
    dest--;
    vector<bool>visited(n,0);
    vector<int>parent(n,-1);
    queue<int>q;
    q.push(src);
    visited[src]=1;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        for (int i=0;i<Adj[node].size();i++) {
            if (visited[Adj[node][i]])
                continue;
            visited[Adj[node][i]]=1;
            q.push(Adj[node][i]);
            parent[Adj[node][i]]=node;
        }
    }
    vector<int>ans;
    while (dest!=-1) {
        ans.push_back(dest+1);
        dest=parent[dest];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int n,m;
    cout<<"Entre The Vertex Number: ";
    cin>>n;
    cout<<"Entre The Size of Edges: ";
    cin>>m;
    vector<pair<int,int>>edges(m);
    for (int i=0;i<m;i++) {
        cout<<"Entre The Element: ";
        cin>>edges[i].first>>edges[i].second;
    }
    int src,dest;
    cout<<"Entre The Source: ";
    cin>>src;
    cout<<"Entre The DEst: ";
    cin>>dest;
    vector<int>ans=Shortest_paths(edges,n,src,dest);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }

}
