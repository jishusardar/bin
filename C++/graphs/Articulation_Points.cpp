//
// Created by jishu on 31-10-2025.
//Articulation Points In a Graph
#include<iostream>
#include <vector>
using namespace std;
void DFS(int node,int parent,vector<int>&disc,vector<int>&low,vector<int>adj[],vector<bool>&art,int &count,vector<bool>&visited) {
    visited[node]=1;
    disc[node]=low[node]=count;
    int child=0;
    for (int j=0;j<adj[node].size();j++) {
        int neigh=adj[node][j];
        if (parent==neigh)
            continue;
        else if (visited[neigh]) {
            low[node]=min(low[node],disc[neigh]);
        }
        else {
            count++;
            child++;
            DFS(neigh,node,disc,low,adj,art,count,visited);
            low[node]=min(low[node],low[neigh]);
            if (disc[node]<=low[neigh]&&parent!=-1)
                art[node]=1;
        }
    }
    if (child>1&&parent==-1)
        art[node]=1;
}
vector<int> Articulation_Points(int V,vector<int>adj[]) {
    vector<int>disc(V);
    vector<int>low(V);
    vector<bool>visited(V,0);
    vector<bool>Art(V,0);
    int count=0;
    DFS(0,-1,disc,low,adj,Art,count,visited);
    vector<int>ans;
    for (int i=0;i<V;i++) {
        if (Art[i])
        ans.push_back(i);
    }
    return ans;
}
int main() {
    int v=5;
    vector<int>adj[]= {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};
    vector<int>abs=Articulation_Points(v,adj);
    for (int i=0;i<abs.size();i++) {
        cout<<abs[i]<<" ";
    }
}
