//
// Created by jishu on 18-10-2025.
//painter Allocation
#include<iostream>
using namespace std;
int Painter_Allocation(int n,int arr[],int m) {
    int start=0,end=0,ans=-1;
    for (int i=0;i<n;i++) {
        start=max(start,arr[i]);
        end+=arr[i];
    }
    while (start<=end) {
        int mid=start+(end-start)/2;
        int painter=1,walls=0;
        for (int i=0;i<n;i++) {
            walls+=arr[i];
            if (walls>mid) {
                walls=arr[i];
                painter++;
            }
        }
        if (painter>m)
            start=mid+1;
        else {
            ans=mid;
            end=mid-1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int m;
    cout<<"Entre The No of painter: ";
    cin>>m;
    cout<<Painter_Allocation(n,arr,m);
}
