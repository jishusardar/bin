//
// Created by jishu on 27-08-2025.
//minimum size subarray sum
#include <iostream>
#include <vector>
using namespace std;
int minimumsizesubarraysum(vector<int>&arr,int target) {
    int start=0,end=0,ans=INT_MAX,sum=0;
    while (end<arr.size()) {
        sum+=arr[end];
        while (sum>=target&&start<=end) {
            ans=min(ans,end-start+1);
            sum-=arr[start];
            start++;
        }
        end++;
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
    int k;
    cout<<"Entre The Target: ";
    cin>>k;
    cout<<"The Minimum Lenght Of Subarray with Sum k: "<<minimumsizesubarraysum(arr,k);
}
