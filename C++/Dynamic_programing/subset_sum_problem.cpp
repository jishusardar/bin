//
// Created by jishu on 23-03-2026.
//subset sum problem
#include<iostream>
#include <vector>
using namespace std;
//bruteforce method 1
// bool find(int sum,int n,vector<int>&arr) {
//     if (sum==0)
//         return 1;
//     if (n==0)
//         return 0;
//     if (sum<arr[n-1])
//         return find(sum,n-1,arr);
//     else
//         return find(sum-arr[n-1],n-1,arr)||find(sum,n-1,arr);
// }
//top down approach
// bool find(int sum,int n,vector<int>&arr,vector<vector<int>>&dp) {
//     if (sum==0)
//         return 1;
//     if (n==0)
//         return 0;
//     if (dp[n][sum]!=-1)
//         return dp[n][sum];
//     if (sum<arr[n-1])
//         return dp[n][sum]=find(sum,n-1,arr,dp);
//     else
//         return dp[n][sum]=find(sum-arr[n-1],n-1,arr,dp)||find(sum,n-1,arr,dp);
// }
//bottom up approach
// bool find(int sum,int n,vector<int>&arr,vector<vector<int>>&dp) {
//     for (int i=0;i<=sum;i++)
//         dp[0][i]=0;
//     for (int i=0;i<=n;i++)
//         dp[i][0]=1;
//
//     for (int i=1;i<=n;i++) {
//         for (int j=1;j<=sum;j++) {
//             if (j<arr[i-1])
//                 dp[i][j]=dp[i-1][j];
//             else
//                 dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
//         }
//     }
//     return dp[n][sum];
// }
//more optimization
// bool find(int sum,int n,vector<int>&arr) {
//     //we can soleve the space complexity using 2 arrays
//     //one final and another previous
//     vector<int>prev(sum+1,0);
//     vector<int>dp(sum+1,0);
//     prev[0]=1;
//     dp[0]=1;
//     for (int i=1;i<=n;i++) {
//         for (int j=1;j<=sum;j++) {
//             if (j<arr[i-1])
//                 dp[j]=prev[j];
//             else
//                 dp[j]=prev[j-arr[i-1]]||prev[j];
//         }
//         prev=dp;
//     }
//     return dp[sum];
// }
//more optimization now using 1 array only
// bool find(int sum,int n,vector<int>&arr) {
//     vector<int>dp(sum+1,0);
//     dp[0]=1;
//     for (int i=1;i<=n;i++) {
//         for (int j=sum;j>=arr[i-1];j--) {
//             dp[j]=dp[j-arr[i-1]]||dp[j];
//         }
//     }
//     return dp[sum];
// }
//bruteforce method 2
// bool find(int sum,int index,int n,vector<int>&arr) {
//     if (sum==0)
//         return 1;
//     if (index==n)
//         return 0;
//     if (sum<arr[index])
//         return find(sum,index+1,n,arr);
//     else
//         return find(sum-arr[index],index+1,n,arr)||find(sum,index+1,n,arr);
// }
//top down approach method 2
// bool find(int sum,int index,int n,vector<int>&arr,vector<vector<int>>&dp) {
//     if (sum==0)
//         return 1;
//     if (index==n)
//         return 0;
//     if (dp[index][sum]!=-1)
//         return dp[index][sum];
//     if (sum<arr[index])
//         return dp[index][sum]=find(sum,index+1,n,arr,dp);
//     else
//         return dp[index][sum]=find(sum-arr[index],index+1,n,arr,dp)||find(sum,index+1,n,arr,dp);
// }
//bottom up apparoach
// bool find(int sum,int n,vector<int>&arr) {
//     vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
//     for (int i=0;i<=sum;i++)
//         dp[n][i]=0;
//     for (int i=0;i<=n;i++)
//         dp[i][0]=1;
//     for (int i=n-1;i>=0;i--) {
//         for (int j=1;j<=sum;j++) {
//             if (j<arr[i])
//                 dp[i][j]=dp[i+1][j];
//             else
//                 dp[i][j]=dp[i+1][j-arr[i]]||dp[i+1][j];
//         }
//     }
//     //last jaha pe value interprit ho raha hai
//     return dp[0][sum];
// }
//more optimization
// bool find(int sum,int n,vector<int>&arr) {
//     vector<int>dp(sum+1,0);
//     vector<int>next(sum+1,0);
//     dp[0]=1;
//     next[0]=1;
//     for (int i=n-1;i>=0;i--) {
//         for (int j=1;j<=sum;j++) {
//             if (j<arr[i])
//                 dp[j]=next[j];
//             else
//                 dp[j]=next[j-arr[i]]||next[j];
//         }
//         next=dp;
//     }
//     return dp[sum];
// }
//more optimization using 1 array method 2
bool find(int sum,int n,vector<int>&arr) {
    vector<int>dp(sum+1,0);
    dp[0]=1;
    for (int i=n-1;i>=0;i--) {
        for (int j=sum;j>=arr[i];j--) {
            dp[j]=dp[j-arr[i]]||dp[j];
        }
    }
    return dp[sum];
}
bool issubsetsum(vector<int>&arr,int sum) {
    int n=arr.size();
    return find(sum,n,arr);
}
int main() {
    int n,sum;
    cout<<"Entre The Size:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Entre The Sum: ";
    cin>>sum;
    if (issubsetsum(arr,sum))
        cout<<"Possible";
    else
        cout<<"Not Possible";
}