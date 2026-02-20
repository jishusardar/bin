// Created by jishu on 20-02-2026.
//minimum number of deletion and insertion
//recursive approach
// #include<iostream>
// #include <vector>
// using namespace std;
// int find(int n,int m,string &s1,string &s2) {
//     if (n==0||m==0)
//         return 0;
//     if (s1[n-1]==s2[m-1])
//         return 1+find(n-1,m-1,s1,s2);
//     else
//         return max(find(n-1,m,s1,s2),find(n,m-1,s1,s2));
// }
// int minimum_number_of_deletion_and_insertion(string &s1,string &s2) {
//     int n=s1.size(),m=s2.size();
//     int lcs=find(n,m,s1,s2);
//     return n-lcs+m-lcs;
// }
// int main() {
//     string s1,s2;
//     cout<<"Entre The String 1: ";
//     cin>>s1;
//     cout<<"Entre The string 2: ";
//     cin>>s2;
//     cout<<minimum_number_of_deletion_and_insertion(s1,s2);
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
//     if (s1[n-1]==s2[m-1])
//         return 1+find(n-1,m-1,s1,s2,dp);
//     else
//         return max(find(n-1,m,s1,s2,dp),find(n,m-1,s1,s2,dp));
// }
// int minimum_number_of_deletion_and_insertion(string &s1,string &s2) {
//     int n=s1.size(),m=s2.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     int lcs=find(n,m,s1,s2,dp);
//     return n-lcs+m-lcs;
// }
// int main() {
//     string s1,s2;
//     cout<<"Entre The String 1: ";
//     cin>>s1;
//     cout<<"Entre The String 2: ";
//     cin>>s2;
//     cout<<minimum_number_of_deletion_and_insertion(s1,s2);
// }
//bottom up approach
#include<iostream>
#include <vector>
using namespace std;
int minimum_number_of_deletion_and_insertion(string &s1,string &s2) {
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][m]+m-dp[n][m];
}
int main() {
    string s1,s2;
    cout<<"Entre The String 1: ";
    cin>>s1;
    cout<<"Entre The String 2: ";
    cin>>s2;
    cout<<minimum_number_of_deletion_and_insertion(s1,s2);
}