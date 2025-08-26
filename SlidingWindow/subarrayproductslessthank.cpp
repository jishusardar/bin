//
// Created by jishu on 27-08-2025.
//subarray products less than k
#include <iostream>
#include <vector>
using namespace std;
int subarrayproductslessthank(vector<int>&arr,int k) {
    int sum=1;
    int start=0,end=0,count=0;
    while (end<arr.size()) {
        sum*=arr[end];
        while (sum>=k&&start<=end) {
            sum/=arr[start];
            start++;
        }
        count+=(end-start+1);
        end++;
    }
    return count;
}
int main() {
    int n,k;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre the Element: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Entre The Kth Term: ";
    cin>>k;
    cout<<"The No Of Subarray's Whose product is less Than k: "<<subarrayproductslessthank(arr,k);
}