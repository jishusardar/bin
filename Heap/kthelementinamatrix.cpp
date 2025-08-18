//
// Created by jishu on 18-08-2025.
//kth element in a matrix
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int kthsmallestinmatrix(vector<vector<int>>&arr,int k) {
    vector<pair<int,pair<int,int>>>temp;
    int n=arr.size();
    for (int i=0;i<n;i++) {
        temp.push_back((make_pair(arr[i][0],make_pair(i,0))));
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q(temp.begin(),temp.end());
    int ans;
    while (k--) {
        pair<int,pair<int,int>>p=q.top();
        q.pop();
        ans=p.first;
        int i=p.second.first;
        int j=p.second.second;
        if (j+1<n)
            q.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
    }
    return ans;
}
int main() {
    int n,m;
    cout<<"Entre The Row And Colms: ";
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<"Entre The Element: ";
            cin>>matrix[i][j];
        }
    }
    int k;
    cout<<"Entre The Kth Element: ";
    cin>>k;
    cout<<"The Kth Smallest Element in Matrix is: "<<kthsmallestinmatrix(matrix,k);
}
