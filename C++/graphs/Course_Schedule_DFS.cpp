//
// Created by jishu on 20-09-2025.
//Course Schedule DFS
#include <algorithm>
#include <filesystem>
#include<iostream>
#include <stack>
#include <variant>
#include <vector>
using namespace std;
bool DFS(int node,vector<bool>&paths,vector<bool>&visited,vector<vector<int>>&Adj,vector<int>&ans) {
    paths[node]=1;
    visited[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        if (paths[Adj[node][i]])
            return 1;
        if (!visited[Adj[node][i]]&&DFS(Adj[node][i],paths,visited,Adj,ans))
            return 1;
    }
    paths[node]=0;
    ans.push_back(node);
    return 0;
}
vector<int> find_Order(int n,vector<vector<int>>&Course) {
    vector<vector<int>>Adj(n);
    for (int i=0;i<Course.size();i++) {
        Adj[Course[i][1]].push_back(Course[i][0]);
    }
    vector<bool>visited(n,0);
    vector<bool>paths(n,0);
    vector<int>ans;
    for (int i=0;i<n;i++) {
        if (!visited[i]&&DFS(i,paths,visited,Adj,ans))
            return vector<int>();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int n,p;
    cout<<"Entre The No Of chars and Adjacent Matrix Size: ";
    cin>>n>>p;
    vector<vector<int>>Adj(p,vector<int>(2));
    for (int i=0;i<Adj.size();i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<Adj[i].size();j++)
            cin>>Adj[i][j];
    }
    vector<int>ans=find_Order(n,Adj);
    if (!ans.size()) {
        cout<<"The Course Cycle is Invalid";
    }
    else {
        for (int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
    }
}
