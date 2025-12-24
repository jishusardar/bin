//
// Created by jishu on 17-10-2025.
//decimal to binary
#include<iostream>
using namespace std;
int decimal_to_binary(int n) {
    int temp=n;
    int ans=0;
    int mul=1;
    while (temp!=0) {
        int rem=temp%2;
        temp/=2;
        ans+=rem*mul;
        mul*=10;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<decimal_to_binary(n);
}