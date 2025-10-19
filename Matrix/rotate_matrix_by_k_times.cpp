//
// Created by jishu on 20-10-2025.
//Rotate Matrix by K times
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
void rotate_by_90(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++) {
        for (int j=i+1;j<arr[0].size();j++)
            swap(arr[i][j],arr[j][i]);
    }
    for (int i=0;i<arr.size();i++) {
        int start=0,end=arr[0].size()-1;
        while (start<=end) {
            swap(arr[i][start],arr[i][end]);
            start++,end--;
        }
    }
}
int main() {
    int n,m;
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int sum=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            arr[i][j]=++sum;
    int t;
    cout<<"Entre The Rotation no: ";
    cin>>t;
    while (t) {
        t=t%4;
        rotate_by_90(arr);
        t--;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
