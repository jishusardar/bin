//
// Created by jishu on 12-08-2025.
//kth largest element
//bruteforce use sort then return arr[arr.size()-k+1]
//further optimal use maxheap
//optimize
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int kthlargestelement(vector<int>&arr,int k) {
    priority_queue<int,vector<int>,greater<int>>q;
    for (int i=0;i<k;i++)
        q.push(arr[i]);
    for (int i=k;i<arr.size();i++) {
        if (arr[i]>q.top()) {
            q.pop();
            q.push(arr[i]);
        }
    }
    return q.top();
}
int main() {
    int n,k;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Entre The Kth Term: ";
    cin>>k;
    cout<<"So The Kth Largest Elements is : "<<kthlargestelement(arr,k);
}
