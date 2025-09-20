//
// Created by jishu on 20-09-2025.
//parallel Course
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int minimumtime(int n,vector<vector<int>>&rela,vector<int>&time) {
    vector<vector<int>>Adj(n);
    vector<int>indegree(n,0);
    for (int i=0;i<rela.size();i++) {
        Adj[rela[i][0]-1].push_back(rela[i][1]-1);
        indegree[rela[i][1]]++;
    }
    queue<int>q;
    vector<int>ct(n,0);
    for (int i=0;i<n;i++) {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        for (int i=0;i<Adj[node].size();i++) {
            indegree[Adj[node][i]]--;
            if (indegree[Adj[node][i]]==0)
                q.push(Adj[node][i]);
            ct[Adj[node][i]]=max(ct[Adj[node][i]],time[node]+ct[node]);
        }
    }
    int ans=0;
    for (int i=0;i<n;i++) {
        ans=max(ans,time[i]+ct[i]);
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The No of Vertex: ";
    cin>>n;
    int m;
    cout<<"Entre The No of m: ";
    cin>>m;
    vector<vector<int>>rela(m,vector<int>(2));
    for (int i=0;i<m;i++) {
        cout<<"Entre The Elements: ";
        cin>>rela[i][0]>>rela[i][1];
    }
    vector<int>time(n);
    for (int i=0;i<n;i++) {
        cout<<"Entre The Time: ";
        cin>>time[i];
    }
    cout<<"Minimum Time to complete Courses: "<<minimumtime(n,rela,time);
}
