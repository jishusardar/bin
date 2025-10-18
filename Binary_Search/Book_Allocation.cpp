//
// Created by jishu on 18-10-2025.
//Book Allocation
//we have to distribute books into nums students
//arr[i] contains no of pages
#include<iostream>
#include <vector>
using namespace std;
int Book_Allocation(int arr[],int n,int nums) {
    int start=0,end=0,ans=-1;
    for (int i=0;i<n;i++) {
        end+=arr[i];
        start=max(start,arr[i]);
    }
    while (start<=end) {
        int mid=start+(end-start)/2;
        int pages=0,dist=1;
        for (int i=0;i<n;i++) {
            pages+=arr[i];
            if (pages>mid) {
                pages=arr[i];
                dist++;
            }
        }
        if (dist>nums) {
            start=mid+1;
        }
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
    cout<<"Entre The No. of Students: ";
    cin>>m;
    cout<<Book_Allocation(arr,n,m);
}
