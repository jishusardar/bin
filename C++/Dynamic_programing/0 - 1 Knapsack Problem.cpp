//
// Created by jishu on 15-02-2026.
//0-1 knapsack problem
//brute force using recursion
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int index,int w,vector<int>&val,vector<int>&wt) {
//     if (w==0)
//         return 0;
//     if (index==0)
//         return 0;
//     if (wt[index-1]>w)
//         return find(index-1,w,val,wt);
//     else
//         return max(val[index-1]+find(index-1,w-wt[index-1],val,wt),find(index-1,w,val,wt));
// }
// int knapsack_problem(int W,vector<int>&val,vector<int>&wt) {
//     int n=wt.size();
//     return find(n,W,val,wt);
// }
// int main() {
//     int n,w;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     cout<<"Entre The Weight: ";
//     cin>>w;
//     vector<int>val(n);
//     vector<int>wt(n);
//     cout<<"Entre The Weights: ";
//     for (int i=0;i<n;i++)
//         cin>>wt[i];
//     cout<<"Entre The Values: ";
//     for (int i=0;i<n;i++)
//         cin>>val[i];
//     cout<<knapsack_problem(w,val,wt);
// }
//top down approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int index,int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp) {
//     if (w==0)
//         return 0;
//     if (index==0)
//         return 0;
//     if (dp[index][w]!=-1)
//         return dp[index][w];
//     if (wt[index-1]>w)
//         return dp[index][w]=find(index-1,w,val,wt,dp);
//     else
//         return dp[index][w]=max(val[index-1]+find(index-1,w-wt[index-1],val,wt,dp),find(index-1,w,val,wt,dp));
// }
// int knapsack_problem(int w,vector<int>&val,vector<int>&wt) {
//     int n=wt.size();
//     vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
//     return find(n,w,val,wt,dp);
// }
// int main() {
//     int n,w;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     cout<<"Entre The Weight: ";
//     cin>>w;
//     vector<int>val(n);
//     cout<<"Entre The values: ";
//     for (int i=0;i<n;i++)
//         cin>>val[i];
//     vector<int>wt(n);
//     cout<<"Entre The Weights: ";
//     for (int i=0;i<n;i++)
//         cin>>wt[i];
//     cout<<knapsack_problem(w,val,wt);
// }
//bottom up apparoach
// #include<iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n,w;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     cout<<"Entre The Weight: ";
//     cin>>w;
//     vector<int>val(n);
//     cout<<"Entre The values: ";
//     for (int i=0;i<n;i++)
//         cin>>val[i];
//     vector<int>wt(n);
//     cout<<"Entre The Weights: ";
//     for (int i=0;i<n;i++)
//         cin>>wt[i];
//     vector<vector<int>>dp(n+1,vector<int>(w+1,0));
//     for (int i=1;i<=n;i++)
//         for (int j=1;j<=w;j++) {
//             if (wt[i-1]>j)
//                 dp[i][j]=dp[i-1][j];
//             else
//                 dp[i][j]=max(val[i-1]+ dp[i-1][j-wt[i-1]],dp[i-1][j]);
//         }
//
//     cout<<dp[n][w];
// }
//knapsack problem space optimized
// #include<iostream>
// #include <vector>
// using namespace std;
// int knapsackproblem(int w,int wt[],int val[],int n) {
//     vector<int>dp(w+1,0);
//     for (int i=1;i<=n;i++)
//         for (int j=w;j>=1;j--) {
//             if (wt[i-1]<=j)
//                 dp[j]=max(val[i-1]+dp[j-wt[i-1]],dp[j]);
//         }
//     return dp[w];
// }
// int main() {
//     int n,w;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     cout<<"Entre The Weight: ";
//     cin>>w;
//     int wt[n];
//     cout<<"Entre The Weight: ";
//     for (int i=0;i<n;i++)
//         cin>>wt[i];
//     int val[n];
//     cout<<"Entre The Value: ";
//     for (int i=0;i<n;i++)
//         cin>>val[i];
//     cout<<knapsackproblem(w,wt,val,n);
// }