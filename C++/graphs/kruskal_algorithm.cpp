//
// Created by jishu on 16-10-2025.
//krushkal algorithm
//is a minimum spanning tree algorithm that works on edges and starts from the least weighted edge
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int FindParent(int u,vector<int>&parent) {
    if (u==parent[u])
        return u;
    return parent[u]=FindParent(parent[u],parent);
}
void UnionByRanks(int u,int v,vector<int>&parent,vector<int>&ranks) {
    int pu=FindParent(u,parent);
    int pv=FindParent(v,parent);
    if (ranks[pu]>ranks[pv])
        parent[pv]=pu;
    else if (ranks[pv]>ranks[pu])
        parent[pu]=pv;
    else {
        parent[pv]=pu;
        ranks[pu]++;
    }
}
int MinimumSpanningTree(int V,vector<vector<int>>Edges) {
    vector<int>Parent(V);
    vector<int>ranks(V,0);
    for (int i=0;i<V;i++)
        Parent[i]=i;
    vector<pair<int,pair<int,int>>>arr;
    for (int i=0;i<Edges.size();i++) {
        arr.push_back({Edges[i][2],{Edges[i][0],Edges[i][1]}});
    }
    int ans=0,edge=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(arr.begin(),arr.end());
    while (!pq.empty()) {
        int wt=pq.top().first;
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        pq.pop();
        if (FindParent(u,Parent)==FindParent(v,Parent))
            continue;
        ans+=wt;
        UnionByRanks(u,v,Parent,ranks);
        edge++;
        if (edge==V-1)
            break;
    }
    return ans;
}
int main() {
    vector<vector<vector<int>>>Edges={{{0, 1, 5}, {1, 2, 3}, {0, 2, 1}},{{0,1,5}}};
    vector<int>V={3,2};
    for (int i=0;i<Edges.size();i++) {
        cout<<"The Solution "<<i+1<<" For Minimum Spanning Tree is: "<<MinimumSpanningTree(V[i],Edges[i])<<endl;
    }
}
