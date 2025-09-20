//
// Created by jishu on 20-09-2025.
//prerequite task using DFS
#include<iostream>
#include <vector>
using namespace std;
bool DFS(int node,vector<int>&paths,vector<int>&visited,vector<vector<int>>&Adj) {
    paths[node]=1;
    visited[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        if (paths[Adj[node][i]])
            return 1;
        if (!visited[Adj[node][i]]&&DFS(Adj[node][i],paths,visited,Adj))
            return 1;
    }
    paths[node]=0;
    return 0;
}
bool is_possible_to_do(int n,int p,vector<vector<int>>&task) {
    vector<vector<int>>Adj(n);
    for (int i=0;i<task.size();i++) {
        Adj[task[i][1]].push_back(task[i][0]);
    }
    vector<int>visited(n,0);
    vector<int>paths(n,0);
    for (int i=0;i<n;i++) {
        if (!visited[i]&&DFS(i,paths,visited,Adj))
            return 0;
    }
    return 1;
}
int main() {
    int n;
    int p;
    cout<<"Entre The No of chars and Tasks: ";
    cin>>n>>p;
    vector<vector<int>>arr(p,vector<int>(2));
    for (int i=0;i<arr.size();i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<arr[i].size();j++)
            cin>>arr[i][j];
    }
    if (is_possible_to_do(n,p,arr))
        cout<<"The Task done is possible";
    else
        cout<<"The Task done is Not Possible";
}
