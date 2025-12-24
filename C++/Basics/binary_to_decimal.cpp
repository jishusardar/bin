//
// Created by jishu on 17-10-2025.
//binary to decinal
#include<iostream>
using namespace std;
int binary_to_decimal(int n) {
    int temp=n;
    int ans=0,mul=1;
    while (temp!=0) {
        int rem=temp%10;
        temp/=10;
        ans+=rem*mul;
        mul*=2;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<binary_to_decimal(n);
}
