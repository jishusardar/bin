//
// Created by jishu on 30-01-2026.
//fibonachi series
#include<iostream>
#include <vector>
using namespace std;
int fibonachi(int n,vector<int>&count) {
    if (n<=1)
        return n;
    if (count[n]!=-1)
        return count[n];
    count[n]=fibonachi(n-1,count)+fibonachi(n-2,count);
    return count[n];
}
int main() {
    int n;
    cin>>n;
    vector<int>count(n+1,-1);
    cout<<fibonachi(n,count);
}
