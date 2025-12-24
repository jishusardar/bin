//
// Created by jishu on 30-08-2025.
//Number of subarrays having sum less than K
#include<iostream>
#include <vector>
using namespace std;
int Numbersubarray(vector<int>&arr,int k) {
    int ans=0;
    int start=0,end=0,sum=0;
    while (end<arr.size()) {
        sum+=arr[end];
        while (sum>=k&&start<=end) {
            sum-=arr[start];
            start++;
        }
        ans+=(end-start+1);
        end++;
    }
    return ans;
}
int main() {
    int n,k;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<arr.size();i++)
        cin>>arr[i];
    cout<<"Entre The Kth Value: ";
    cin>>k;
    cout<<"The No. Of Subarray Having Sum Less Than k is : "<<Numbersubarray(arr,k);
}
