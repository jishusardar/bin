//
// Created by Jishu Sardar on 20/08/25.
//zero sum subarray
//count the no of subarray with sum 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int countzerosumsubarray(vector<int>&arr) {
    int count=0;
    unordered_map<int,int>mm;
    mm[0]=1;
    int sum=0;
    for (int i=0;i<arr.size();i++) {
        sum+=arr[i];
        if (mm[sum]) {
            count+=mm[sum];
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
    cout<<"The No Of Subarray with sum 0 is : "<<countzerosumsubarray(arr);
}