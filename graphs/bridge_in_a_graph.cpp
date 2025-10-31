//
// Created by jishu on 30-10-2025.
//bridge in a graph
//the problem is called critical connections means the connections if removed then heavily effect the whole server system
#include<iostream>
#include <vector>

#include "../tools/converttotest.h"
using namespace std;
void DFS(int node,int parent,vector<int>&disc,vector<int>&low,int &count,vector<bool>&visited,vector<vector<int>>&adj,vector<vector<int>>&ans) {
    disc[node]=low[node]=count;
    visited[node]=1;
    for (int i=0;i<adj[node].size();i++) {
        int neigh=adj[node][i];
        if (neigh==parent)
            continue;
        else if (visited[neigh]) {
            low[node]=min(low[node],low[neigh]);
        }
        else {
            count++;
            DFS(neigh,node,disc,low,count,visited,adj,ans);
            low[node]=min(low[node],low[neigh]);
            if (disc[node]<low[neigh]) {
                ans.push_back({node,neigh});
            }
        }
    }
}
vector<vector<int>> Critical_connections(int n,vector<vector<int>>connections) {
    vector<vector<int>>adj(n);
    for (int i=0;i<connections.size();i++) {
        int u=connections[i][0];
        int v=connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>disc(n);
    vector<int>low(n);
    vector<bool>visited(n,0);
    vector<vector<int>>bridge;
    int count=0;
    DFS(0,-1,disc,low,count,visited,adj,bridge);
    return bridge;
}
int main() {
    // vector<string>adj={"[[0,1],[1,2],[2,0],[1,3]]","[[0,1]]"};
    // converttotest* c1=new converttotest();
    // cout<<c1->convert();
    vector<int>ns={4,2};
    vector<vector<vector<int>>>adj={{{0,1},{1,2},{2,0},{1,3}},{{0,1}}};
    for (int i=0;i<2;i++) {
        vector<vector<int>>ans=Critical_connections(ns[i],adj[i]);
        for (int j=0;j<ans.size();j++) {
            cout<<"["<<ans[j][0]<<","<<ans[j][1]<<"]"<<" ";
        }
        cout<<endl;
    }
}
