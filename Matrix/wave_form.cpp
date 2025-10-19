//
// Created by jishu on 20-10-2025.
//wave form
#include<iostream>
#include <vector>
using namespace std;
void wave_form(vector<vector<int>>&arr) {
    for (int i=0;i<arr[0].size();i++) {
        if (i%2) {
            for (int j=arr.size()-1;j>=0;j--) {
                cout<<arr[j][i]<<" ";
            }
        }
        else {
            for (int j=0;j<arr.size();j++) {
                cout<<arr[j][i]<<" ";
            }
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
        cout<<"Entre The Element: ";
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    wave_form(arr);
}
