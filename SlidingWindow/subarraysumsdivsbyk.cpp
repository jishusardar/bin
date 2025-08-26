//
// Created by jishu on 27-08-2025.
//subarray sums divisible by k
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarraysums(vector<int>&arr,int k) {
    int sum=0;
    unordered_map<int,int>mm;
    mm[0]=1;
    int count=0;
    for (int i=0;i<arr.size();i++) {
        sum+=arr[i];
        int rem=sum%k;
        if (rem<0)
            rem+=k;
        if (mm[rem%k]) {
            count+=mm[rem%k];
        }
        mm[rem%k]++;
    }
    return count;
}
int main() {
    int n,l;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Entre The Kth Term: ";
    cin>>l;
    cout<<"The Subarray Sums are : "<<subarraysums(arr,l);
}