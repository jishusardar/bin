//
// Created by jishu on 20-10-2025.
//print the row index with maximum sum
#include<iostream>
#include <vector>
using namespace std;
int row_index_maximum_sum(vector<vector<int>>&nums) {
    int val=0,ans=-1;
    for (int i=0;i<nums.size();i++) {
        int sum=0;
        for (int j=0;j<nums[i].size();j++) {
            sum+=nums[i][j];
        }
        if (sum>val) {
            val=sum;
            ans=i;
        }
    }
    return ans;
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
    cout<<row_index_maximum_sum(arr);
}
