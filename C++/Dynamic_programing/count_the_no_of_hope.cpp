//
// Created by jishu on 31-01-2026.
//count the no of hopes
// #include<iostream>
// using namespace std;
// int count_no_of_hopes(int m,int n) {
//     if (m==n)
//         return 1;
//     if (m>n)
//         return 0;
//     return count_no_of_hopes(m+1,n)+count_no_of_hopes(m+2,n)+count_no_of_hopes(m+3,n);
// }
// int main() {
//     int n;
//     cin>>n;
//     cout<<count_no_of_hopes(0,n);
// }
//top down approach recursion
#include<iostream>
#include <vector>
using namespace std;
int no_of_hope(int i,int n,vector<int>&dp) {
    if (i==n)
        return 1;
    if (i>n)
        return 0;
    if (dp[i]!=-1)
        return dp[i];
    dp[i]=no_of_hope(i+1,n,dp)+no_of_hope(i+2,n,dp)+no_of_hope(i+3,n,dp);
    return dp[i];
}
int main() {
    int n;
    cin>>n;
    vector<int>dp(n+3,-1);
    cout<<no_of_hope(0,n,dp);
}