//
// Created by jishu on 20-09-2025.
//prerequisite task
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
bool is_possible_to_do(int N,int p,vector<vector<int>>&pre) {
    vector<vector<int>>Adj(N);
    for (int i=0;i<pre.size();i++) {
        Adj[pre[i][1]].push_back(pre[i][0]);
    }
    vector<int>ind(N,0);
    for (int i=0;i<Adj.size();i++) {
        for (int j=0;j<Adj[i].size();j++) {
            ind[Adj[i][j]]++;
        }
    }
    queue<int>q;
    for (int i=0;i<N;i++) {
        if (!ind[i])
            q.push(i);
    }
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        N--;
        for (int i=0;i<Adj[node].size();i++){
            ind[Adj[node][i]]--;
            if (!ind[Adj[node][i]])
                q.push(Adj[node][i]);
        }
    }
    if (N)
        return 0;
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
