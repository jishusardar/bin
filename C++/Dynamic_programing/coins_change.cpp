//
// Created by jishu on 11-02-2026.
//coins change in backward approach bruteforce
#include<iostream>
#include <vector>
using namespace std;
int find(int n,int amount,vector<int>&coins) {
    if (amount==0)
        return 1;
    if (n<0)
        return 0;
    if (coins[n]>amount)
        return find(n-1,amount,coins);
    else
        return find(n,amount-coins[n],coins)+find(n-1,amount,coins);
}
int coin_change(int amount,vector<int>&coins) {
    int n=coins.size();
    return find(n-1,amount,coins);
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
//coins change using top down approach in backward
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int n,int amount,vector<int>&coins,vector<vector<int>>&dp) {
//     if (amount==0)
//         return 1;
//     if (n<0)
//         return 0;
//     if (dp[n][amount]!=-1)
//         return dp[n][amount];
//     if (coins[n]>amount)
//         return dp[n][amount]=find(n-1,amount,coins,dp);
//     else
//         return dp[n][amount]=find(n,amount-coins[n],coins,dp)+find(n-1,amount,coins,dp);
// }
// int coins_change(int amount,vector<int>&coins) {
//     int n=coins.size();
//     vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
//     return find(n-1,amount,coins,dp);
// }
// int main() {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for (int i=0;i<n;i++)
//         cin>>arr[i];
//     int target;
//     cout<<"Entre The Target: ";
//     cin>>target;
//     cout<<coins_change(target,arr);
// }