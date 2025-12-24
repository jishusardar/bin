//
// Created by jishu on 15-08-2025.
//sum of element between k1 and k2
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
long long sumofallelements(vector<long long>&arr,long long k1,long long k2) {
    priority_queue<long long>q1;
    priority_queue<long long>q2;
    for (long long i=0;i<k1;i++)
        q1.push(arr[i]);
    for (long long i=0;i<k2-1;i++)
        q2.push(arr[i]);
    for (long long i=k1;i<arr.size();i++) {
        if (arr[i]<q1.top()) {
            q1.pop();
            q1.push(arr[i]);
        }
    }
    for (long long i=k2-1;i<arr.size();i++) {
        if (arr[i]<q2.top()) {
            q2.pop();
            q2.push(arr[i]);
        }
    }
    long long ans=0;
    while (!q1.empty()) {
        ans+=q1.top();
        q1.pop();
    }
    while (!q2.empty()) {
     ans-=q2.top();
        q2.pop();
    }
    return ans*-1;
}
int main() {
    long long n,k1,k2;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<long long>arr(n);
    cout<<"Entre The Elements: ";
    for (long long i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Entre The K1 and K2 ramge: ";
    cin>>k1>>k2;
    cout<<"The Sum of Elements between k1 and k2 is : "<<sumofallelements(arr,k1,k2);
}
