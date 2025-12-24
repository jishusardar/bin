//
// Created by jishu on 20-10-2025.
//rotate matric by 180 degree
#include<iostream>
#include <vector>
using namespace std;
void rotate_matric_by_180(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++){
        int start=0,end=arr[0].size()-1;
        while (start<=end) {
            swap(arr[i][start],arr[i][end]);
            start++,end--;
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
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int sum=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            arr[i][j]=++sum;
        }
    }
    rotate_matric_by_180(arr);
}
