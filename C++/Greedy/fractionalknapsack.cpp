//
// Created by jishu on 09-01-2026.
//fractional knapsack
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
double fractionalknapsack(int val[],int wt[],int capacity,int n) {
    //sloved using maxheap
    priority_queue<pair<double,int>>pq;
    for (int i=0;i<n;i++) {
        double temp=val[i];
        temp/=wt[i];
        pq.push({temp,i});
    }
    double ans=0;
    while (capacity!=0&&!pq.empty()) {
        if (wt[pq.top().second]<=capacity) {
            capacity-=wt[pq.top().second];
            ans+=val[pq.top().second];
        }
        else {
            ans+=pq.top().first*capacity;
            capacity=0;
        }
        pq.pop();
    }
    return ans;
}
int main() {
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int capapcity=50;
    int n=3;
    cout<<fractionalknapsack(val,wt,capapcity,n);
}
