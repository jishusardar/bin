//
// Created by jishu on 10-09-2025.
//
#include<iostream>
#include <vector>
#include <stack>
using namespace std;
void DFS(vector<vector<int>>&Adj,vector<bool>&visited,stack<int>&ans,int v) {
    visited[v]=1;
    for (int i=0;i<Adj[v].size();i++) {
        if (!visited[Adj[v][i]])
            DFS(Adj,visited,ans,Adj[v][i]);
    }
    ans.push(v);
}
vector<int> topologicalsort(vector<vector<int>>&edges,int v) {
    vector<vector<int>>Adj(v);
    for (int i=0;i<edges.size();i++)
        Adj[edges[i][0]].push_back(edges[i][1]);
    vector<bool>visited(v,0);
    stack<int>st;
    for (int i=0;i<v;i++) {
        if (!visited[i])
        DFS(Adj,visited,st,i);
    }
    vector<int>ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
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
    for (int i=0;i<edges.size();i++) {
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<int>ans=topologicalsort(edges,v);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
