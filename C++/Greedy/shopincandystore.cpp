//
// Created by jishu on 09-01-2026.
//shop in candy store
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
vector<int> shopincandy(int arr[],int k,int n) {
    sort(arr,arr+n);
    vector<int>ans(2,0);
    int i=0,j=n-1;
    while (i<=j) {
        ans[0]+=arr[i];
        i++,j-=k;
    }
    i=0,j=n-1;
    while (i<=j) {
        ans[1]+=arr[j];
        i+=k;
        j--;
    }
    return ans;
}
int main() {
    int n,k;
    cin>>n>>k;
    int prices[n];
    for (int i=0;i<n;i++)
        cin>>prices[i];
    vector<int>ans=shopincandy(prices,k,n);
    cout<<ans[0]<<" "<<ans[1]<<" ";
}
