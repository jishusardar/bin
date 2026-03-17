//
// Created by jishu on 16-03-2026.
//longest common substring
//using bruteforce approach
// #include<iostream>
// using namespace std;
// int find(string &s1,string &s2,int n,int m,int &ans) {
//     if (n==0||m==0)
//         return 0;
//     int len=0;
//     if (s1[n-1]==s2[m-1]) {
//         len=1+find(s1,s2,n-1,m-1,ans);
//         ans=max(ans,len);
//     }
//     find(s1,s2,n-1,m,ans);
//     find(s1,s2,n,m-1,ans);
//     return len;
// }
// int longcommsubstr(string &s1,string &s2) {
//     int n=s1.size(),m=s2.size();
//     int ans=0;
//     find(s1,s2,n,m,ans);
//     return ans;
// }
// int main() {
//     string s1="ABCDGH";
//     string s2="ACDGHR";
//     cout<<longcommsubstr(s1,s2);
// }
//using top down approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(string &s1,string &s2,int n,int m,vector<vector<int>>&dp,int &ans) {
//     if (n==0||m==0)
//         return 0;
//     if (dp[n][m]!=-1)
//         return dp[n][m];
//     int len=0;
//     if (s1[n-1]==s2[m-1]) {
//         len=1+find(s1,s2,n-1,m-1,dp,ans);
//         ans=max(ans,len);
//     }
//     find(s1,s2,n-1,m,dp,ans);
//     find(s1,s2,n,m-1,dp,ans);
//     return dp[n][m]=len;
// }
// int longcommsubstr(string &s1,string &s2) {
//     int ans=0;
//     int n=s1.size(),m=s2.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     find(s1,s2,n,m,dp,ans);
//     return ans;
// }
// int main() {
//     string s1="ABCDGH";
//     string s2="ACDGHR";
//     cout<<longcommsubstr(s1,s2);
// }
//using bottom up approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int longcommsubstr(string &s1,string &s2) {
//     int ans=0;
//     int n=s1.size(),m=s2.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//     for (int i=1;i<=n;i++) {
//         for (int j=1;j<=m;j++) {
//             if (s1[i-1]==s2[j-1]) {
//                 dp[i][j]=1+dp[i-1][j-1];
//                 ans=max(ans,dp[i][j]);
//             }
//         }
//     }
//     return ans;
// }
// int main() {
//     string s1="ABCDGH";
//     string s2="ACDGHR";
//     cout<<longcommsubstr(s1,s2);
// }