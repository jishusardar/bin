//
// Created by jishu on 17-03-2026.
//longest increasing subsequence
//bruteforce approach
//time complexity o(n^2)
// #include<iostream>
// #include <vector>
// using namespace std;
// int lis(vector<int>&arr) {
//     int n=arr.size();
//     vector<int>temp(n,1);
//     for (int i=1;i<n;i++) {
//         for (int j=i-1;j>=0;j--) {
//             if (arr[i]>arr[j]) {
//                 temp[i]=max(temp[i],temp[j]+1);
//             }
//         }
//     }
//     int ans=0;
//     for (int i=0;i<n;i++) {
//         ans=max(ans,temp[i]);
//     }
//     return ans;
// }
// int main() {
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     cout<<"Entre The Elements: ";
//     for (int i=0;i<n;i++)
//         cin>>arr[i];
//     cout<<lis(arr);
// }
//optimized approach
//time complexity nlog(n)
#include <iostream>
#include <vector>
using namespace std;
int lis(vector<int>&arr) {
    int n=arr.size();
    vector<int>temp(n);
    int start,end,size=0,index;
    temp[0]=arr[0];
    for (int i=1;i<n;i++) {
        start=0,end=size,index=size+1;
        while (start<=end) {
            int mid=start+(end-start)/2;
            if (temp[mid]<arr[i]) {
                start=mid+1;
            }
            else if (temp[mid]==arr[i]) {
                index=mid;
                break;
            }
            else {
                index=mid;
                end=mid-1;
            }
        }
        temp[index]=arr[i];
        size=max(size,index);
    }
    return size+1;
}
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<lis(arr);
}
