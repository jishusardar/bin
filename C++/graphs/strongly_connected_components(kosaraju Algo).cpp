//
// Created by jishu on 07-11-2025.
//
#include <algorithm>
#include<iostream>
#include <stack>
#include <vector>
using namespace std;
void topology(int node,vector<vector<int>>&Adj,vector<bool>&visited,stack<int>&s) {
    visited[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        if (!visited[Adj[node][i]]) {
            topology(Adj[node][i],Adj,visited,s);
        }
    }
    s.push(node);
}
void DFS(int node,vector<vector<int>>&Adj,vector<bool>&visited) {
    visited[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        if (!visited[Adj[node][i]]) {
            DFS(Adj[node][i],Adj,visited);
        }
    }
}
int SCC(int V,vector<vector<int>>&Adj) {
    stack<int>s;
    vector<bool>visited(V,0);
    for (int i=0;i<V;i++) {
        if (!visited[i])
            topology(i,Adj,visited,s);
    }
    for (int i=0;i<V;i++)
        visited[i]=0;
    vector<vector<int>>Adj2(V);
    for (int i=0;i<V;i++) {
        int u=i;
        for (int j=0;j<Adj[i].size();j++) {
            int v=Adj[i][j];
            Adj2[v].push_back(u);
        }
    }
    int ans=0;
    while (!s.empty()) {
        int node=s.top();
        s.pop();
        if (!visited[node]) {
            ans++;
            DFS(node,Adj,visited);
        }
    }
    return ans;

}
int main() {
}
