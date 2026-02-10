//
// Created by jishu on 11-02-2026.
//coins change using simple recursion
#include<iostream>
#include <vector>
using namespace std;
int find(int index,int amount,int n,vector<int>&coins) {
    if (amount==0)
        return 1;
    if (index>=n||amount<0)
        return 0;
    return find(index,amount-coins[index],n,coins)+find(index+1,amount,n,coins);
}
int coin_change(int amount,vector<int>&coins) {
    int n=coins.size();
    return find(0,amount,n,coins);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cout<<"Entre The Target: ";
    cin>>target;
    cout<<coin_change(target,arr);
}
//coins change II using top down approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int index,int amount,int n,vector<int>&coins,vector<vector<int>>&dp) {
//     if (amount==0)
//         return 1;
//     if (index>=n||amount<0)
//         return 0;
//     if (dp[index][amount]!=-1)
//         return dp[index][amount];
//     return find(index,amount-coins[index],n,coins,dp)+find(index+1,amount,n,coins,dp);
// }
// int coins_change(int amount,vector<int>&coins) {
//     int n=coins.size();
//     vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
//     return find(0,amount,n,coins,dp);
// }
// int main() {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for (int i=0;i<n;i++)
//         cin>>arr[i];
//     int target;
//     cout<<"Entre The target: ";
//     cin>>target;
//     cout<<coins_change(target,arr);
// }
