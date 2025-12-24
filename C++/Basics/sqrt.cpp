//
// Created by jishu on 17-10-2025.
//find square root of any number
#include<iostream>
using namespace std;
int sqrt(int n) {
    int start=0,end=n,ans=-1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (mid==n/mid)
            return mid;
        else if (mid>n/mid) {
            end=mid-1;
        }
        else {
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<sqrt(n);
}
