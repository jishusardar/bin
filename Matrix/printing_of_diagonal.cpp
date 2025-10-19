//
// Created by jishu on 20-10-2025.
//printing of diagonal
#include<iostream>
#include <vector>
using namespace std;
void printing_of_diagonal(vector<vector<int>>&arr) {
    for (int i=0;i<arr.size();i++) {
        int j=i,k=0;
        while (j>=0&&k<arr[0].size()) {
            cout<<arr[j][k]<<" ";
            j--,k++;
        }
    }
    for (int i=1;i<arr[0].size();i++) {
        int j=i,k=arr.size()-1;
        while (k>=0&&j<arr[0].size()) {
            cout<<arr[k][j]<<" ";
            k--,j++;
        }
    }
}
int main() {
    int n,m;
    cout<<"Entre The Row and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int sum=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++)
            arr[i][j]=++sum;
    }
    printing_of_diagonal(arr);
}
