//
// Created by jishu on 18-10-2025.
//First and last Position of Element in sorted array
#include<iostream>
#include <vector>
using namespace std;
vector<int> Positions(vector<int>&arr,int val) {
    int start=0,end=arr.size()-1;
    vector<int>ans(2);
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (arr[mid]==val) {
            ans[0]=mid-1;
            ans[1]=mid;
            return ans;
        }
        else if (arr[mid]>val)
            end=mid-1;
        else
            start=mid+1;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int val;
    cout<<"Entre The Value:";
    cin>>val;
    vector<int>position=Positions(arr,val);
    cout<<position[0]<<position[1]<<" ";
}
