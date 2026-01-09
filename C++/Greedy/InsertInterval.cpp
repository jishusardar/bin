//
// Created by jishu on 09-01-2026.
//Insert Interval
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>>Inertinterval(vector<vector<int>>&arr,vector<int>interval) {
    vector<vector<int>>ans;
    int i=0,n=arr.size();
    while (i<n&&interval[0]>arr[i][1]) {
        ans.push_back(arr[i]);
        i++;
    }
    if (i==n) {
        ans.push_back(interval);
        return ans;
    }
    while (i<n&&interval[1]>=arr[i][0]) {
        interval[0]=min(interval[0],arr[i][0]);
        interval[1]=max(interval[1],arr[i][1]);
        i++;
    }
    ans.push_back(interval);
    while (i<n) {
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
}
int main() {
    vector<vector<int>>arr={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int>interval={4,8};
    vector<vector<int>>ans=Inertinterval(arr,interval);
   for (int i=0;i<ans.size();i++) {
       for (int j=0;j<ans[i].size();j++)
           cout<<ans[i][j]<<" ";
       cout<<endl;
   }
}
