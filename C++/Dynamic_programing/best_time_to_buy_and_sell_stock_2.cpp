//
// Created by jishu on 22-03-2026.
//best time to buy and sell stock 2
#include<iostream>
#include <vector>
using namespace std;
int buyandsell(vector<int>&prices) {
    int ans=0;
    for (int i=1;i<prices.size();i++) {
        if (prices[i]>prices[i-1])
            ans+=prices[i]-prices[i-1];
    }
    return ans;
}
int main() {
    vector<int>prices={7,1,5,3,6,4};
    cout<<buyandsell(prices);
}
