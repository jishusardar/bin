//
// Created by jishu on 22-03-2026.
//best time to buy and sell stocks
#include<iostream>
#include <vector>
using namespace std;
int buy_sell(vector<int>&prices) {
    int n=prices.size();
    int stock=prices[0],ans=0;
    for (int i=1;i<n;i++) {
        ans=max(ans,prices[i]-stock);
        stock=min(stock,prices[i]);
    }
    return ans;
}
int main() {
    vector<int>prices={7,1,5,3,6,4};
    cout<<buy_sell(prices);
}
