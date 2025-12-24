//
// Created by jishu on 07-10-2025.
//Check Either it is Euler Path or Euler Circuit or neither both
#include<iostream>
#include <vector>
using namespace std;
void DFS(vector<int>Adj[],int node,vector<bool>&visited) {
    visited[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        if (!visited[Adj[node][i]])
            DFS(Adj,Adj[node][i],visited);
    }
}
int Detect(vector<int>Adj[],int V) {
    vector<int>degree(V);
    int odd_deg=0;
    for (int i=0;i<V;i++) {
        degree[i]=Adj[i].size();
        if (degree[i]%2)
            odd_deg++;
    }
    if (odd_deg!=0&&odd_deg!=2)
        return 0;
    vector<bool>visited(V,0);
    for (int i=0;i<V;i++) {
        if (degree[i]) {
            DFS(Adj,i,visited);
            break;
        }
    }
    //if the graph is disconnected and all disconnected cannot be visited so that kind of graphs will not considered eulerian paths
    for(int i=0;i<V;i++){
        if(!degree[i]&&visited[i])
            return 0;
    }
    if (odd_deg)
        return 1;
    return 2;
}
int main() {
    int v=3;
    vector<int>Adj[]={{1,2},{0,2},{0,1}};
    int ans=Detect(Adj,v);
    if (ans==1)
        cout<<"its a Eulerian Path";
    if (ans==2)
        cout<<"Its a Eulerian Circuit";
    if (!ans)
        cout<<"its Neither a Eulerian Path or Circuit";
}
