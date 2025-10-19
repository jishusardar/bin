//
// Created by jishu on 20-10-2025.
//Add Matrix
#include<iostream>
#include <vector>
using namespace std;
void Add_Matrix(vector<vector<int>>arr1,vector<vector<int>>arr2) {
    vector<vector<int>>ans(arr1.size(),vector<int>(arr1[0].size()));
    for (int i=0;i<arr1.size();i++) {
        for (int j=0;j<arr1[i].size();j++)
        ans[i][j]=arr1[i][j]+arr2[i][j];
    }
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n,m;
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    cout<<"Matrix 1: "<<endl;
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    vector<vector<int>>arr2(n,vector<int>(m));
    cout<<"Matrix 2: "<<endl;
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++)
            cin>>arr2[i][j];
    }
    Add_Matrix(arr,arr2);
}
