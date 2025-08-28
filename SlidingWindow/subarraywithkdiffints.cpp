//
// Created by Jishu Sardar on 29/08/25.
//subarray with k different integers
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int atleast(vector<int>&arr,int k) {
    int start=0,end=0,count=0;
    unordered_map<int,int>mm;
    while (end<arr.size()) {
        mm[arr[end]]++;
        while (mm.size()>=k) {
            count+=arr.size()-end;
            mm[arr[start]]--;
            if (mm[arr[start]]==0)
                mm.erase(arr[start]);
            start++;
        }
        end++;
    }
    return count;
}
int atmost(vector<int>&arr,int k) {
    int start=0,end=0,count=0;
    unordered_map<int,int>mm;
    while (end<arr.size()) {
        mm[arr[end]]++;
        while (mm.size()>k) {
            mm[arr[start]]--;
            if (mm[arr[start]]==0)
                mm.erase(arr[start]);
            start++;
        }
        count+=end-start+1;
        end++;
    }
    return count;
}
int approach1(vector<int>&arr,int k) {
    //using atleast k - atleast k-1
   return atleast(arr,k)-atleast(arr,k+1);
}
int approach2(vector<int>&arr,int k) {
    return atmost(arr,k)-atmost(arr,k-1);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Entre The Kth Term: ";
    cin>>k;
    cout<<"The No of Subarray With K different integers: "<<approach2(arr,k);
}