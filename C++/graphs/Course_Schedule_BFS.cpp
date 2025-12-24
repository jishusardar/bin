//
// Created by jishu on 20-09-2025.
//Course Schedule using BFS
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> find_order(int n,vector<vector<int>>&pre) {
    vector<vector<int>>Adj(n);
    for (int i=0;i<Adj.size();i++) {
        for (int j=0;j<Adj[i].size();j++) {
            Adj[pre[i][1]].push_back(pre[i][0]);
        }
    }
    vector<int>indeg(n,0);
    for (int i=0;i<Adj.size();i++) {
        for (int j=0;j<Adj[i].size();j++)
            indeg[Adj[i][j]]++;
    }
    queue<int>q;
    vector<int>ans;
    for (int i=0;i<indeg.size();i++) {
        if (!indeg[i])
            q.push(i);
    }
    while (!q.empty()) {
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for (int i=0;i<Adj[node].size();i++) {
            indeg[Adj[node][i]]--;
            if (indeg[Adj[node][i]]==0)
                q.push(Adj[node][i]);
        }
    }
    return ans.size()==n?ans:vector<int>();
}
int main() {
    int n,p;
    cout<<"Entre The No Of Chars and Size of Adjacent Matrix: ";
    cin>>n>>p;
    vector<vector<int>>Adj(p,vector<int>(2));
    for (int i=0;i<Adj.size();i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<Adj[i].size();j++)
            cin>>Adj[i][j];
    }
    vector<int>ans=find_order(n,Adj);
    if (!ans.size())
        cout<<"The Course Schedule is invalid";
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
