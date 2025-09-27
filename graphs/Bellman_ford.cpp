//
// Created by jishu on 28-09-2025.
//Bellman Ford Algorithm applicable on directed graph that does not have negative cycle
#include<iostream>
#include <vector>
using namespace std;
vector<int>Bellman_Ford(int V,vector<vector<int>>&edges,int src) {
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for (int i=0;i<V;i++) {
        bool check=0;
        for (int j=0;j<edges.size();j++) {
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if (dist[u]==INT_MAX)
                continue;
            if (dist[u]+wt<dist[v]) {
                dist[v]=dist[u]+wt;
                check=1;
            }
        }
        if (!check)
            return dist;
        if (i==V-1&&check)
            return {-1};
    }
    return dist;
}
int main() {
    vector<int>Vertex={5,4};
    vector<vector<vector<int>>>Edges={{{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}},{{0, 1, 4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}}};
    vector<int>Source={0,0};
    for (int i=0;i<2;i++) {
        vector<int>ans=Bellman_Ford(Vertex[i],Edges[i],Source[i]);
        for (int j=0;j<ans.size();j++) {
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
}
