//
// Created by jishu on 20-10-2025.
//Transpose of matrix
#include<iostream>
#include <vector>
using namespace std;
void Transpose_of_Matrix(vector<vector<int>>&nums) {
    for (int i=0;i<nums.size();i++) {
        for (int j=i+1;j<nums[i].size();j++) {
            swap(nums[i][j],nums[j][i]);
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
    Transpose_of_Matrix(arr);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
