//
// Created by jishu on 18-10-2025.
//Kth Missing positiive Integer
#include <emmintrin.h>
#include<iostream>
#include <vector>
using namespace std;
int Kth_missing(vector<int>&arr,int k) {
    int start=0,end=arr.size()-1;
    int ans;
    if (k<=0)
        return -1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (arr[mid]-mid-1>=k) {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans+k;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Entre The Kth Term: ";
    cin>>k;
    cout<<Kth_missing(arr,k);
}