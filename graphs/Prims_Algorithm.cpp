//
// Created by jishu on 15-10-2025.
//Prims Algorithm minimum spanning tree
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int Minimum_Spanning_Tree(int v,vector<vector<int>>&Edges) {
    vector<vector<pair<int,int>>>Adj(v);
    for (int i=0;i<Edges.size();i++) {
        Adj[Edges[i][0]].push_back({Edges[i][1],Edges[i][2]});
        Adj[Edges[i][1]].push_back({Edges[i][0],Edges[i][2]});
    }
    vector<bool>isMst(v,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    int ans=0;
    while (!q.empty()) {
        int wt=q.top().first;
        int node=q.top().second;
        q.pop();
        if (isMst[node])
            continue;
        isMst[node]=1;
        ans+=wt;
        for (int i=0;i<Adj[node].size();i++) {
            if (!isMst[Adj[node][i].first]) {
                q.push({Adj[node][i].second,Adj[node][i].first});
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<vector<int>>>Edges={{{0, 1, 5}, {1, 2, 3}, {0, 2, 1}},{{0,1,5}}};
    vector<int>V={3,2};
    for (int i=0;i<2;i++) {
        cout<<"The Minimum Spanning Tree Weight is : "<<Minimum_Spanning_Tree(V[i],Edges[i])<<endl;
    }

}
