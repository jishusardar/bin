//
// Created by jishu on 21-09-2025.
//find shortest path to every node from a source node in undirected graph
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> shortest_paths(vector<vector<int>>&Adj,int source) {
    vector<bool>visited(Adj.size(),0);
    //intialize the distance by -1 for reason of disconnected graph
    vector<int>dist(Adj.size(),-1);
    queue<int>q;
    q.push(source);
    dist[source]=0;
    visited[source]=1;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        for (int i=0;i<Adj[node].size();i++) {
            if (!visited[Adj[node][i]]) {
                visited[Adj[node][i]]=1;
                q.push(Adj[node][i]);
                dist[Adj[node][i]]=dist[node]+1;
            }
        }
    }
    return dist;
}
int main() {
    int src;
    vector<vector<vector<int>>>adj={{{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}},{{3}, {3}, {}, {0, 1}}};
    for (int i=0;i<adj.size();i++) {
        cout<<"Entre The Source: ";
        cin>>src;
        vector<int>ans=shortest_paths(adj[i],src);
        for (int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
