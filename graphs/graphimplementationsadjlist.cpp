//
// Created by jishu on 05-09-2025.
//Graph implementation using adjacency list
#include<iostream>
#include <vector>
using namespace std;
void undirectedgraph(int vertex,int edge) {
    vector<int>Adjlist[vertex];
    int u,v;
    for (int i=0;i<edge;i++) {
        cin>>u>>v;
        Adjlist[u].push_back(v);
        Adjlist[v].push_back(u);
    }
    for (int i=0;i<vertex;i++) {
        cout<<i<<"->";
        for (int j=0;j<Adjlist[i].size();j++)
            cout<<Adjlist[i][j]<<" ";
        cout<<endl;
    }
}
void undirectedweightedgraph(int vertex,int edge) {
    vector<pair<int,int>>AdjList[vertex];
    int u,v,data;
    for (int i=0;i<edge;i++) {
        cin>>u>>v>>data;
        AdjList[u].push_back(make_pair(v,data));
        AdjList[v].push_back(make_pair(u,data));
    }
    for (int i=0;i<vertex;i++) {
        cout<<i<<"->";
        for (int j=0;j<AdjList[i].size();j++)
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" ";
        cout<<endl;
    }
}
void directedgraph(int vertex,int edge) {
    vector<int>AdjList[vertex];
    int u,v;
    for (int i=0;i<edge;i++) {
        cin>>u>>v;
        AdjList[u].push_back(v);
    }
    for (int i=0;i<vertex;i++) {
        cout<<i<<"->";
        for (int j=0;j<AdjList[i].size();j++)
            cout<<AdjList[i][j]<<" ";
        cout<<endl;
    }
}
void directedweightedgraph(int vertex,int edge) {
    vector<pair<int,int>>AdjList[vertex];
    int u,v,data;
    for (int i=0;i<edge;i++) {
        cin>>u>>v>>data;
        AdjList[u].push_back(make_pair(v,data));
    }
    for (int i=0;i<vertex;i++) {
        cout<<i<<"->";
        for (int j=0;j<AdjList[i].size();j++)
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" ";
        cout<<endl;
    }
}
int main() {
    int vertex,edge;
    cin>>vertex>>edge;
    //undirectedgraph(vertex,edge);
   // undirectedweightedgraph(vertex,edge);
    //directedgraph(vertex,edge);
    //directedweightedgraph(vertex,edge);
}
