//
// Created by jishu on 12-08-2025.
//kth smallest element
//bruteforce approach use sorting
//further optimize use minheap
//most optimal
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int kthsmallestnumber(vector<int>&arr,int k) {
    priority_queue<int>q;
    for (int i=0;i<k;i++)
        q.push(arr[i]);
    for (int i=k;i<arr.size();i++) {
        if (arr[i]<q.top()) {
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
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Entre The Kth Term: ";
    cin>>k;
    cout<<"So The Kth Smallest Element is : "<<kthsmallestnumber(arr,k);
}
