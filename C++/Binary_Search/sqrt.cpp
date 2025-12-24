//
// Created by jishu on 18-10-2025.
//sqrt
#include <cmath>
#include<iostream>
using namespace std;
int Sqrt(int n) {
    int start=0,end=n-1,ans;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (mid==n/mid)
            return mid;
        else if (mid>n/mid)
            end=mid-1;
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
    cout<<Sqrt(n);
}
