//
// Created by jishu on 08-09-2025.
//Traverse graph apply BFS
#include<iostream>
#include <queue>
#include <vector>
#include <pstl/execution_impl.h>
using namespace std;
vector<int> BFS(vector<vector<int>>&Adjmatrix) {
    vector<int>ans;
    queue<int>q;
    vector<bool>visited(Adjmatrix.size(),0);
    q.push(0);
    visited[0]=1;
    while(!q.empty()) {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for (int i=0;i<Adjmatrix[node].size();i++) {
            if (!visited[Adjmatrix[node][i]]) {
                visited[Adjmatrix[node][i]]=1;
                q.push(Adjmatrix[node][i]);
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>>Adjmatrix={{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<int>ans=BFS(Adjmatrix);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }

}
