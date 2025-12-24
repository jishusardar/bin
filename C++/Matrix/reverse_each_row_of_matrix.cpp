//
// Created by jishu on 20-10-2025.
//reverse each row of matrix
#include<iostream>
#include <vector>
using namespace std;
void Reverse_each_row(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++) {
        int start=0,end=arr[0].size()-1;
        while (start<end) {
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
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    Reverse_each_row(arr);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
