//
// Created by jishu on 09-01-2026.
//assign mice holes
#include <algorithm>
#include<iostream>
using namespace std;
int assignmiceholes(int n,int mices[],int holes[]) {
    sort(mices,mices+n);
    sort(holes,holes+n);
    int ans=INT_MIN;
    for (int i=0;i<n;i++) {
        ans=max(ans,abs(mices[i]-holes[i]));
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    for (int i=0;i<n;i++)
        cin>>arr1[i];
    for (int i=0;i<n;i++)
        cin>>arr2[i];
    cout<<assignmiceholes(n,arr1,arr2);
}
