// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int findMissing(vector<int> &arr) {
//         // code here
//         int d=INT_MAX;
//         for(int i=0;i<arr.size()-1;i++){
//             d=min(d,abs(arr[i]-arr[i+1]));
//         }
//         for(int i=0;i<arr.size()-1;i++){
//             if(arr[i]+d!=arr[i+1]&&arr[i]<arr[i+1])
//             return arr[i]+d;
//         }
//         // if(arr[0]<arr[arr.size()-1])
//         return arr[arr.size()-1]+d;
//         // for(int i=0;i<arr.size()-1;i++){
//         //     if(arr[i]-d!=arr[i+1]&&arr[i]>arr[i+1])
//         //     return arr[i]-d;
//         // }
//         // return arr[arr.size()-1]-d;
//     }
int removeDuplicates(vector<int> &arr) {
        // code here
        vector<int>ans;
        ans.push_back(arr[0]);
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            if(ans[ans.size()-1]!=arr[i])
            ans.push_back(arr[i]);
        }
        return ans.size();
    }
int main() {
    // Write C++ code here
    vector<int>arr={32,40,43,60,72,78,82,82,82,99};
    cout<<removeDuplicates(arr);
}