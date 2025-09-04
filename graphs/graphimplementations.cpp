//
// Created by jishu on 04-09-2025.
//implement graph using adjacency matrix
#include<iostream>
#include <vector>
using namespace std;
void undirectedgraph(int vertex,int edge) {
    vector<vector<bool>>Adjmatric(vertex,vector<bool>(vertex,0));
    int u,v;
    for (int i=0;i<edge;i++) {
        cin>>u>>v;
        Adjmatric[u][v]=1;
        Adjmatric[v][u]=1;
    }
    for (int i=0;i<vertex;i++) {
        for (int j=0;j<vertex;j++)
            cout<<Adjmatric[i][j]<<" ";
        cout<<endl;
    }
}
void undirectedweighted(int vertex,int edge) {
    vector<vector<int>>Adjmatrix(vertex,vector<int>(vertex,0));
    int u,v,data;
    for (int i=0;i<edge;i++) {
        cin>>u>>v>>data;
        Adjmatrix[u][v]=data;
        Adjmatrix[v][u]=data;
    }
    for (int i=0;i<vertex;i++) {
        for (int j=0;j<vertex;j++)
            cout<<Adjmatrix[i][j]<<" ";
        cout<<endl;
    }
}
void directedgraph(int vertex,int edge) {
    vector<vector<bool>>AdjMatrix(vertex,vector<bool>(vertex,0));
    int u,v;
    for (int i=0;i<edge;i++) {
        cin>>u>>v;
        AdjMatrix[u][v]=1;
    }
    for (int i=0;i<vertex;i++) {
        for (int j=0;j<vertex;j++)
            cout<<AdjMatrix[i][j]<<" ";
        cout<<endl;
    }
}
void directedweightedgraph(int vertex,int edge) {
    vector<vector<int>>Adjmatrix(vertex,vector<int>(vertex,0));
    int u,v,data;
    for (int i=0;i<edge;i++) {
        cin>>u>>v>>data;
        Adjmatrix[u][v]=data;
    }
    for (int i=0;i<vertex;i++) {
        for (int j=0;j<vertex;j++)
            cout<<Adjmatrix[i][j]<<" ";
        cout<<endl;
    }
}
int main() {
    int v,e;
    cout<<"Entre The Vertex and Edge: ";
    cin>>v>>e;
    //undirectedgraph(v,e);
    //undirectedweighted(v,e);
    //directedgraph(v,e);
    //directedweightedgraph(v,e);
    //time complexity O(v2)
    //space complexity O(v2)
}
