//
// Created by jishu on 12-08-2025.
//kth largest in stream
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>KthlargestinStream(vector<int>&arr,int k)
{
    vector<int>ans(arr.size(),-1);
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(0);
    for (int i=0;i<k-1;i++) {
        q.push(arr[i]);
    }
    for (int i=k-1;i<arr.size();i++) {
        if (arr[i]>q.top()) {
            if (!q.empty())
            q.pop();
            q.push(arr[i]);
        }
        ans[i]=q.top();
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
}
