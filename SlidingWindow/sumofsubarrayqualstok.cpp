//
// Created by Jishu Sardar on 20/08/25.
//sum of subarray equals to k
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarrayswithsumsk(vector<int>&arr,int k) {
    int sum=0;
    int count=0;
    unordered_map<int,int>mm;
    mm[0]=1;
    for (int i=0;i<arr.size();i++) {
        sum+=arr[i];
        if (mm[sum-k]) {
            count+=mm[sum-k];
        }
        mm[sum]++;
    }
    return count;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Entre The K Term: ";
    cin>>k;
    cout<<"The Count Of Subarray is : "<<subarrayswithsumsk(arr,k);
}