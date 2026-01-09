//
// Created by jishu on 09-01-2026.
//Job Sequencing Problem
#include <algorithm>
#include<iostream>
#include <queue>
#include <vector>
#include <pstl/execution_defs.h>
using namespace std;
int find(int num,vector<int>&parent) {
    if (num==parent[num])
        return num;
    return parent[num]=find(parent[num],parent);
}
vector<int>jobsequence(int deadline[],int profit[],int n) {
    vector<int>ans(2,0);
    int m=0;
    for (int i=0;i<n;i++) {
        m=max(m,deadline[i]);
    }
    vector<int>parent(m+1);
    for (int i=0;i<parent.size();i++)
        parent[i]=i;
    vector<pair<int,int>>pq;
    for (int i=0;i<n;i++) {
        pq.push_back({profit[i],deadline[i]});
    }
    sort(pq.rbegin(),pq.rend());
    for (int i=0;i<n;i++) {
        int slot=find(pq[i].second,parent);
        if (slot>0) {
            ans[0]++;
            ans[1]+=pq[i].first;
            parent[slot]=slot-1;
        }
    }
    return ans;
}
int main() {
    int n=4;
    int deadline[]={4,1,1,1};
    int profit[]={20,10,40,30};
    vector<int>ans=jobsequence(deadline,profit,n);
    cout<<ans[0]<<" "<<ans[1]<<" ";
}
