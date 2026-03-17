//
// Created by jishu on 17-03-2026.
//longest arithmatic progression
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;
//using map approach
// int lengthoflongestAP(vector<int>&arr) {
//     int n=arr.size();
//     int ans=2;
//     if (n<=2)
//         return n;
//     unordered_map<int,int>mm[n];
//     for (int i=1;i<n;i++) {
//         for (int j=i-1;j>=0;j--) {
//             int diff=arr[i]-arr[j];
//             if (mm[j][diff]!=0) {
//                 mm[i][diff]=max(mm[i][diff],1+mm[j][diff]);
//                 ans=max(ans,mm[i][diff]);
//             }
//             else {
//                 if (!mm[i][diff])
//                     mm[i][diff]=2;
//             }
//         }
//     }
//     return ans;
// }
// int main() {
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for (int i=0;i<n;i++)
//         cin>>arr[i];
//     cout<<lengthoflongestAP(arr);
// }
//longest arithmatic progression
//using dp approach
#include <iostream>
#include <vector>
using namespace std;
int lengthOfLongestAp(vector<int>&arr) {
    int n=arr.size();
    int ans=2;
    if (n<=2)
        return n;
    int maxi=INT_MIN,mini=INT_MAX;
    for (int i=0;i<n;i++) {
        maxi=max(maxi,arr[i]);
        mini=min(mini,arr[i]);
    }
    vector<vector<int>>dp(n+1,vector<int>(maxi-mini+1,0));
    for (int i=1;i<n;i++) {
        for (int j=i-1;j>=0;j--) {
            int diff=arr[i]-arr[j];
            if (dp[j][diff]!=0) {
                dp[i][diff]=max(dp[i][diff],1+dp[j][diff]);
                ans=max(ans,dp[i][diff]);
            }
            else {
                if (!dp[i][diff])
                    dp[i][diff]=2;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elemenets: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<lengthOfLongestAp(arr);
}