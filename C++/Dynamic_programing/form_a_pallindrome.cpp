//
// Created by jishu on 20-02-2026.
//form a pallindrome
//recrsive approach
// #include <algorithm>
// #include<iostream>
// using namespace std;
// int find(int n,int m,string &s1,string &s2) {
//     if (n==0||m==0)
//         return 0;
//     if (s1[n-1]==s2[m-1])
//         return 1+find(n-1,m-1,s1,s2);
//     else
//         return max(find(n-1,m,s1,s2),find(n,m-1,s1,s2));
// }
// int form_a_pallindrome(string &s) {
//     int n=s.size();
//     string s2=s;
//     reverse(s2.begin(),s2.end());
//     int lcs=find(n,n,s,s2);
//     return n-lcs;
// }
// int main() {
//     string s;
//     cout<<"Entre The String 1: ";
//     cin>>s;
//     cout<<form_a_pallindrome(s);
// }
//top down approach
// #include <algorithm>
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int n,int m,string &s1,string &s2,vector<vector<int>>&dp) {
//     if (n==0||m==0)
//         return 0;
//     if (dp[n][m]!=-1)
//         return dp[n][m];
//     if (s1[n-1]==s2[m-1])
//         return dp[n][m]=1+find(n-1,m-1,s1,s2,dp);
//     else
//         return dp[n][m]=max(find(n-1,m,s1,s2,dp),find(n,m-1,s1,s2,dp));
// }
// int form_a_pallindrome(string &s) {
//     int n=s.size();
//     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//     string s2=s;
//     reverse(s2.begin(),s2.end());
//     int lcs=find(n,n,s,s2,dp);
//     return n-lcs;
// }
// int main() {
//     string s;
//     cout<<"Entre The String 1: ";
//     cin>>s;
//     cout<<form_a_pallindrome(s);
// }
//bottom up approach
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
int form_a_pallindrome(string &s) {
    int n=s.size();
    string s1=s;
    reverse(s1.begin(),s1.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) {
            if (s[i-1]==s1[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return n-dp[n][n];
}
int main() {
    string s;
    cout<<"Entre The String 1: ";
    cin>>s;
    cout<<form_a_pallindrome(s);
}