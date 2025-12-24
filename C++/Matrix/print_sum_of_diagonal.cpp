//
// Created by jishu on 20-10-2025.
//print sum of diagonal elements
#include<iostream>
#include <vector>
using namespace std;
int sum_of_diagonal_elements(vector<vector<int>>&arr) {
    int sum=0;
    for (int i=0;i<arr.size();i++) {
        sum+=arr[i][i];
    }
    int start=0,end=arr[0].size()-1;
    while (end>=0&&start<arr.size()) {
        sum+=arr[start][end];
        start++,end--;
    }
    return sum;
}
int main() {
    int n,m;
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Element: ";
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    cout<<sum_of_diagonal_elements(arr);
}
