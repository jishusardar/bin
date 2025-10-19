//
// Created by jishu on 20-10-2025.
//rotate matrix by 90
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
void rotate_matrix_by_90(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++)
        for (int j=i+1;j<arr[0].size();j++)
            swap(arr[i][j],arr[j][i]);
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
    cout<<"Entre The Rows and Colms: ";
    cin>>n>>m;
    int sum=0;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            arr[i][j]=++sum;
    rotate_matrix_by_90(arr);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
