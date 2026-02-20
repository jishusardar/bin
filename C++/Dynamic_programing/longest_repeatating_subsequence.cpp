// Created by jishu on 20-02-2026.
//longest repetating subsequence
//recursive approach
// #include<iostream>
// using namespace std;
// int find(int n,int m,string &s1,string &s2) {
//     if (n==0||m==0)
//         return 0;
//     if (s1[n-1]==s2[m-1]&&n!=m)
//         return 1+find(n-1,m-1,s1,s2);
//     else
//         return max(find(n-1,m,s1,s2),find(n,m-1,s1,s2));
// }
// int LongestRepeatingSubsequence(string &s1) {
//     string s2=s1;
//     int n=s1.size(),m=s2.size();
//     return find(n,m,s1,s2);
// }
// int main() {
//     string s;
//     cout<<"Entre The string: ";
//     cin>>s;
//     cout<<LongestRepeatingSubsequence(s);
// }
//top down approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int n,int m,string &s1,string &s2,vector<vector<int>>&dp) {
//     if (n==0||m==0)
//         return 0;
//     if (dp[n][m]!=-1)
//         return dp[n][m];
//     if (s1[n-1]==s2[m-1]&&n!=m)
//         return 1+find(n-1,m-1,s1,s2,dp);
//     else
//         return max(find(n-1,m,s1,s2,dp),find(n,m-1,s1,s2,dp));
// }
// int LongestRepeatingSubsequence(string &s1) {
//     string s2=s1;
//     int n=s1.size(),m=s2.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     cout<<find(n,m,s1,s2,dp);
// }
// int main() {
//     string s;
//     cout<<"Entre The string: ";
//     cin>>s;
//     cout<<LongestRepeatingSubsequence(s);
// }
//bottom up approach
#include<iostream>
#include <vector>
using namespace std;
int LongestRepeatingSubsequence(string &s1) {
    string s2=s1;
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            if (s1[i-1]==s2[j-1]&&i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return dp[n][m];
}
int main() {
    string s;
    cout<<"Entre The String : ";
    cin>>s;
    cout<<LongestRepeatingSubsequence(s);
}