//
// Created by jishu on 09-01-2026.
//Single-Threaded CPU
#include <algorithm>
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> singlethreadedCPU(vector<vector<int>>&tasks) {
    vector<int>ans;
    int n=tasks.size();
    for (int i=0;i<n;i++) {
        tasks[i].push_back(i);
    }
    sort(tasks.begin(),tasks.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int i=0,timer=tasks[0][0];
    while (i<n||!pq.empty()) {
        while (i<n&&timer>=tasks[i][0]) {
            pq.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        if (pq.empty()) {
            timer=tasks[i][0];
        }
        else {
            timer+=pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
}
int main() {
    vector<vector<int>>arr={{1,2},{2,4},{3,2},{4,1}};
    vector<int>ans=singlethreadedCPU(arr);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
