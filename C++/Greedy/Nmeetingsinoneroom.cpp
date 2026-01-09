//N meetings in one room
#include <algorithm>
#include<iostream>
#include <queue>
using namespace std;
int Nmeetings(vector<int>&start,vector<int>&end){
    vector<pair<int,int>>arr;
    for (int i=0;i<start.size();i++) {
        arr.push_back({start[i],end[i]});
    }
    sort(arr.begin(),arr.end());
    int ans=1;
    for (int i=1;i<arr.size();i++) {
        if (arr[i-1].second>arr[i].first)
            ans++;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];
    cout<<Nmeetings(start,end);
}