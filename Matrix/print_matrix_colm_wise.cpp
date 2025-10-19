//
// Created by jishu on 20-10-2025.
//print matrix column wise
#include<iostream>
#include <vector>
using namespace std;
void print_maxtrix(vector<vector<int>>mat) {
    for (int i=0;i<mat[i].size();i++) {
        for (int j=0;j<mat.size();j++) {
            cout<<mat[j][i]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n,m;
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    print_maxtrix(arr);
}
