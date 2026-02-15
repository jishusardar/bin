//
// Created by jishu on 11-02-2026.
// //coins change in backward approach bruteforce
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int n,int amount,vector<int>&coins) {
//     if (amount==0)
//         return 1;
//     if (n<0)
//         return 0;
//     if (coins[n]>amount)
//         return find(n-1,amount,coins);
//     else
//         return find(n,amount-coins[n],coins)+find(n-1,amount,coins);
// }
// int coin_change(int amount,vector<int>&coins) {
//     int n=coins.size();
//     return find(n-1,amount,coins);
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
//     cout<<coin_change(target,arr);
// }
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
//bottom up approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int coin_change(int amount,vector<int>&coins) {
//     int n=coins.size();
//     vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
//     for (int i=0;i<=n;i++)
//         dp[i][0]=1;
//     for (int i=1;i<=n;i++)
//         for (int j=1;j<=amount;j++) {
//             if (coins[i-1]>j)
//                 dp[i][j]=dp[i-1][j];
//             else
//                 dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
//         }
//     return dp[n][amount];
// }
// int main() {
//     int n,amount;
//     cout<<"Entre the Size: ";
//     cin>>n;
//     vector<int>coins(n);
//     cout<<"Entre The Element: ";
//     for (int i=0;i<n;i++)
//         cin>>coins[i];
//     cout<<"Entre The amount: ";
//     cin>>amount;
//     cout<<coin_change(amount,coins);
// }
//more optimized approach
#include<iostream>
#include <vector>
using namespace std;
int coin_change(int amount,vector<int>&coins) {
    vector<int>dp(amount+1,0);
    dp[0]=1;
    int n=coins.size();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=amount;j++) {
            if (coins[i-1]<=j)
                dp[j]+=dp[j-coins[i-1]];
        }
    return dp[amount];
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The coins: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int amount;
    cout<<"Entre The Amount: ";
    cin>>amount;
    cout<<coin_change(amount,arr);
}