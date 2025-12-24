//
// Created by jishu on 17-10-2025.
//Armstrong Number
#include<iostream>
#include <math.h>
using namespace std;
int digits(int n) {
    return log(n)/log(10)+1;
}
bool Armstrong_no(int n) {
    int temp=n,ans=0;
    int m=digits(n);
    while (temp!=0) {
        int rem=temp%10;
        temp/=10;
        ans+=pow(rem,m);
    }
    if (ans==n)
        return 1;
    return 0;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<Armstrong_no(n);
}
