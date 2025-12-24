//
// Created by Jishu Sardar on 29/08/25.
//length of longest subarray with most k frequency
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int lengthofsubarraywithatmostk(vector<int>&nums,int k) {
    int start=0,end=0,len=0;
    unordered_map<int,int>mm;
    while (end<nums.size()) {
        mm[nums[end]]++;
        while (mm[nums[end]]>k) {
            mm[nums[start]]--;
            start++;
        }
        len=max(len,end-start+1);
        end++;
    }
    return len;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elmenet: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Entre The Value of k: ";
    cin>>k;
    cout<<"The Length Of The Longest Subarray with atmost K frequency of each Elmenet: "<<lengthofsubarraywithatmostk(arr,k);
}