//
// Created by jishu on 20-10-2025.
//Spiral Form
#include<iostream>
#include <vector>
using namespace std;
void Spiral_Form(vector<vector<int>>&arr) {
    int top=0,left=0,right=arr[0].size()-1,bottom=arr.size()-1;
    while (top<=bottom&&left<=right) {
        for (int i=left;i<=right;i++) {
            cout<<arr[top][i]<<" ";
        }
        top++;
        for (int i=top;i<=bottom;i++) {
            cout<<arr[i][right]<<" ";
        }
        right--;
        if (top<=bottom) {
            for (int i=right;i>=left;i--) {
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        if (left<=right) {
            for (int i=bottom;i>=top;i--) {
                cout<<arr[i][left]<<" ";
            }
            left++;
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
        for (int j=0;j<m;j++)
            arr[i][j]=++sum;
    }
    Spiral_Form(arr);
}
