//
// Created by jishu on 20-10-2025.
//rotate matrix k times anticlock wise
#include<iostream>
#include <vector>
using namespace std;
void rotate_matrix_by_90_anticlock(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++) {
        for (int j=i+1;j<arr[0].size();j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }
    for (int i=0;i<arr[0].size();i++) {
        int start=0,end=arr.size()-1;
        while (start<end) {
            swap(arr[start][i],arr[end][i]);
            start++,end--;
        }
    }
}
int main() {
    int n,m;
    cout<<"Entre The Rows and Colm: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int sum=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            arr[i][j]=++sum;
        }
    }
    int k;
    cout<<"Entre The Rotatin: ";
    cin>>k;
    while (k!=0) {
        k=k%4;
        rotate_matrix_by_90_anticlock(arr);
        k--;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
