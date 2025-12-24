//
// Created by jishu on 17-10-2025.
//reverse A Digit
#include<iostream>
using namespace std;
int Reverse_digit(int n) {
    int ans=0;
    while (n!=0) {
        int rem=n%10;
        n/=10;
        if (ans>INT_MAX/10||ans<INT_MIN/10)
            return 0;
        ans=ans*10+rem;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Digits: ";
    cin>>n;
    cout<<Reverse_digit(n);
}
