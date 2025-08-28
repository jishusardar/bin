//
// Created by Jishu Sardar on 29/08/25.
//count the subarray where max Element Appear at Least K Times
#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;
int approach1(vector<int>&arr,int k) {
    int start=0,end=0,count=0;
    int maximum=INT_MIN;
    for (int i=0;i<arr.size();i++)
        maximum=max(maximum,arr[i]);
    unordered_map<int,int>mm;
    while (end<arr.size()) {
        mm[arr[end]]++;
        while (mm[maximum]>=k) {
            count+=arr.size()-end;
            mm[arr[start]]--;
            start++;
        }
        end++;
    }
    return count;
    //time complexity O(n)
    //space Complexity O(n)
    //using map
}
int approach2(vector<int>&arr,int k) {
    int start=0,end=0,count=0,maximum=INT_MIN,ans=0;
    for (int i=0;i<arr.size();i++)
        maximum=max(maximum,arr[i]);
    while (end<arr.size()) {
        if (arr[end]==maximum)
            count++;
        while (count>=k) {
            ans+=arr.size()-end;
            if (arr[start]==maximum)
                count--;
            start++;
        }
        end++;
    }
    return ans;
    //time complexity O(n)
    //space complexity 0(1)
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elmennt: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Entre The Value of k: ";
    cin>>k;
    cout<<"The Count of The Subarray Where The Max Element Appears at Atleast K Times: "<<approach2(arr,k);
}