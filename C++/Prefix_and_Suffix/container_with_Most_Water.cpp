//
// Created by jishu on 19-10-2025.
//container with most water
#include<iostream>
#include <vector>
using namespace std;
int container_with_most_Water(vector<int>&arr) {
    int start=0,end=arr.size()-1;
    int ans=0;
    while (start<=end) {
        ans=max(ans,min(arr[start],arr[end])*(end-start));
        if (arr[start]>arr[end])
            end--;
        else
            start++;
    }
    return ans;
    //time complexity O(n)
}
int main() {
    vector<vector<int>>arr={{1,8,6,2,5,4,8,3,7},{1,1}};
    for (int i=0;i<arr.size();i++) {
        cout<<container_with_most_Water(arr[i])<<" ";
    }
}
