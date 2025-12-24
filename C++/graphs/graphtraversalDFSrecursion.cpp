//
// Created by jishu on 08-09-2025.
//Graph Traversal applying DFS using recursion
#include<iostream>
#include <vector>
using namespace std;
void Traversal(vector<vector<int>>&AdjMatrix,vector<bool>&visited,int v,vector<int>&ans) {
    visited[v]=1;
    ans.push_back(v);
    for (int i=0;i<AdjMatrix[v].size();i++) {
        if (!visited[AdjMatrix[v][i]]){
            Traversal(AdjMatrix,visited,AdjMatrix[v][i],ans);
        }
    }
    return;
}
vector<int> DFS(vector<vector<int>>Adjmatrix) {
    vector<int>ans;
    vector<bool>visited(Adjmatrix.size(),0);
    Traversal(Adjmatrix,visited,0,ans);
    return ans;
}
int main() {
    vector<vector<int>>AdjMatrix={{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int>ans=DFS(AdjMatrix);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}
