//
// Created by jishu on 20-10-2025.
//Rotate matrix by 90 anticlockwise
#include<iostream>
#include <vector>
using namespace std;
void rotate_matrix_by_90_anti(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++) {
        for (int j=i+1;j<arr[0].size();j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }
    for (int i=0;i<arr[0].size();i++) {
        int start=0,end=arr.size()-1;
        while (start<=end) {
            swap(arr[start][i],arr[end][i]);
            start++,end--;
        }
    }
    for (int i=0;i<arr.size();i++) {
        for (int j=0;j<arr[0].size();j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n,m;
    cout<<"Entre The Row and Colm: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int sum=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            arr[i][j]=++sum;
        }
    }
    rotate_matrix_by_90_anti(arr);
}
