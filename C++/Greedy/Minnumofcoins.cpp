//
// Created by jishu on 09-01-2026.
//Min Number Of Coins
#include<iostream>
using namespace std;
int curency[]={10,5,2,1};
int main() {
    int n;
    cout<<"Entre The Amout: ";
    cin>>n;
    int count=0;
    for (int i=0;i<4;i++) {
        if(n/curency[i]>0) {
            count+=n/curency[i];
            n%=curency[i];
        }
    }
    cout<<"Total No of coins is: "<<count<<" ";
}
