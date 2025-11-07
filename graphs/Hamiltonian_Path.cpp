//
// Created by jishu on 02-11-2025.
//Hamiltonian Path
//har vertex ko ekbar visit karna hai
#include<iostream>
#include <vector>
using namespace std;
bool DFS(int node,vector<vector<int>>&adj,vector<bool>&visited,int &count,int n) {
    visited[node]=1;
    count++;
    for (int i=0;i<adj[node].size();i++) {
        if (!visited[adj[node][i]]&&DFS(adj[node][i],adj,visited,count,n))
            return 1;
    }
    visited[node]=0;
    count--;
    return 0;
}
bool Hamiltonian_Path(int n,int m,vector<vector<int>>&Edges) {
    vector<vector<int>>Adj(n);
    for (int i=0;i<m;i++) {
        Edges[Adj[i][0]-1].push_back(Adj[i][1]-1);
        Edges[Adj[i][1]-1].push_back(Adj[i][0]-1);
    }
    vector<bool>visited(n,0);
    int count=0;
    for (int i=0;i<n;i++) {
        if (DFS(i,Adj,visited,count,n))
            return 1;
    }
    return 0;
}
int main() {
    vector<int>Ns={4,4};
    vector<int>Ms={4,3};
    vector<vector<vector<int>>>Edge{{ {1,2}, {2,3}, {3,4}, {2,4} },{ {1,2}, {2,3}, {2,4} }};
    for (int i=0;i<2;i++) {
        cout<<Hamiltonian_Path(Ns[i],Ms[i],Edge[i]);
    }
}
