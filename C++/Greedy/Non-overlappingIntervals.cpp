//
// Created by jishu on 09-01-2026.
//Non-overlapping Intervals
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
int non_Intervals(vector<vector<int>>&intervals) {
    int n=intervals.size();
    for (int i=0;i<n;i++) {
        swap(intervals[i][0],intervals[i][1]);
    }
    sort(intervals.begin(),intervals.end());
    int ans=1;//0 index pehle sai count me hai
    int end=intervals[0][0];
    for (int i=1;i<n;i++) {
        if (end<=intervals[i][1]) {
            ans++;
            end=intervals[i][0];
        }
    }
    return n-ans;
}
int main() {
    vector<vector<int>>intervals={{{1,2},{2,3},{3,4},{1,3}}};
    cout<<non_Intervals(intervals);
}