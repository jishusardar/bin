//
// Created by jishu on 15-02-2026.
//count ways to Nth Stair(Order does not matter)
//recursive method
// #include<iostream>
// #include <vector>
// using namespace std;
// int mov[]={1,2};
// int find(int index,int n) {
//     if (n==0)
//         return 1;
//     if (index==0)
//         return 0;
//     if (mov[index-1]>n)
//         return find(index-1,n);
//     else
//         return find(index,n-mov[index-1])+find(index-1,n);
// }
// int nthStair(int n) {
//     return find(2,n);
// }
// int main() {
//     int n;
//     cout<<"Entre The Nth term: ";
//     cin>>n;
//     cout<<nthStair(n);
// }
//top down approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int mov[]={1,2};
// int find(int index,int n,vector<vector<int>>&dp) {
//     if (n==0)
//         return 1;
//     if (index==0)
//         return 0;
//     if (dp[index][n]!=-1)
//         return dp[index][n];
//     if (mov[index-1]>n)
//         return dp[index][n]=find(index-1,n,dp);
//     else
//         return dp[index][n]=find(index,n-mov[index-1],dp)+find(index-1,n,dp);
// }
// int nthstair(int n) {
//     vector<vector<int>>dp(3,vector<int>(n+1,-1));
//     return find(2,n,dp);
// }
// int main() {
//     int n;
//     cout<<"Entre The Stair: ";
//     cin>>n;
//     cout<<nthstair(n);
// }
//bottom up approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int mov[]={1,2};
// int nthstair(int n) {
//     vector<vector<int>>dp(3,vector<int>(n+1,0));
//     for (int i=0;i<3;i++)
//         dp[i][0]=1;
//     for (int i=1;i<=2;i++) {
//         for (int j=1;j<=n;j++) {
//             if (mov[i-1]>j)
//                 dp[i][j]=dp[i-1][j];
//             else
//                 dp[i][j]=dp[i][j-mov[i-1]]+dp[i-1][j];
//         }
//     }
//     return dp[2][n];
// }
// int main() {
//     int n;
//     cout<<"Entre The Stair No: ";
//     cin>>n;
//     cout<<nthstair(n);
// }