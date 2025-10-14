//
// Created by jishu on 14-10-2025.
//circle of string
#include<iostream>
#include <vector>
using namespace std;
void DFS(int node,vector<vector<int>>Adj,vector<bool>&visited) {
    visited[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        if (!visited[Adj[node][i]])
            DFS(Adj[node][i],Adj,visited);
    }
}
bool isCircle(vector<string>&arr) {
    vector<vector<int>>Adj(26,vector<int>());
    vector<int>Indeg(26,0);
    vector<int>Outdeg(26,0);
    for (int i=0;i<arr.size();i++) {
        string temp=arr[i];
        int u=temp[0]-'a';
        int v=temp[temp.size()-1]-'a';
        Adj[u].push_back(v);
        Indeg[v]++;
        Outdeg[u]++;
    }
    for (int i=0;i<26;i++) {
        if (Indeg[i]!=Outdeg[i])
            return 0;
    }
    vector<bool>visited(26,0);
    DFS(arr[0][0]-'a',Adj,visited);
    for (int i=0;i<26;i++) {
        if (Indeg[i]&&!visited[i])
            return 0;
    }
    return 1;
}
int main() {
    vector<vector<string>>arr={{"abc", "bcd", "cdf"},{"ab" , "bc", "cd", "da"}};
    for (int i=0;i<arr.size();i++) {
        if (isCircle(arr[i]))
            cout<<"The Circle is Formed"<<endl;
        else
            cout<<"The Circle Cannot be Formed"<<endl;
    }
}
