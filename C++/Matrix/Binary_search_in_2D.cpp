//
// Created by jishu on 20-10-2025.
//Binary Search In 2D array
#include<iostream>
#include <vector>
using namespace std;
bool finds(vector<vector<int>>&arr,int x) {
    int i=0,j=arr[0].size()-1;
    while (i<arr.size()&&j>=0) {
        if (arr[i][j]==x)
            return 1;
        else if (arr[i][j]>x)
            j--;
        else
            i++;
    }
    return 0;
}
int main() {
    int n,m;
    cout<<"Entre The Rows and Colms: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int sum=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++)
            arr[i][j]=++sum;
    }
    int x;
    cout<<"Entre The Target: ";
    cin>>x;
    cout<<finds(arr,x);

}
