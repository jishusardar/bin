//
// Created by jishu on 17-10-2025.
//check the number is pallindrome or not
#include<iostream>
using namespace std;
bool is_Pallindrome(int n) {
    if (n<0)
        return 0;
    int temp=n,ans=0;
    while (temp!=0) {
        int rem=temp%10;
        temp/=10;
        ans=ans*10+rem;
    }
    if (ans==n)
        return 1;
    return 0;
}
int main() {
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    cout<<is_Pallindrome(n);
}
