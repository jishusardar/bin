//
// Created by jishu on 08-09-2025.
//graph traversal applying DFS using stack(instead of recursion)
#include<iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> DFS(vector<vector<int>>&Adjmat) {
    vector<int>ans;
    stack<int>st;
    vector<int>vis(Adjmat.size(),0);
    st.push(0);
    while (!st.empty()) {
        int v=st.top();
        st.pop();
        if (!vis[v])
        ans.push_back(v);
        vis[v]=1;
        for (int i=Adjmat[v].size()-1;i>=0;i--) {
            if (!vis[Adjmat[v][i]]) {
               st.push(Adjmat[v][i]);
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>>Adjmat={{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int>ans=DFS(Adjmat);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
