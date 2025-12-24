//
// Created by jishu on 17-10-2025.
//Add Digits
#include <iostream>
using namespace std;
int Break_down(int n) {
    int ans=0;
    while (n!=0) {
        int rem=n%10;
        n/=10;
        ans+=rem;
    }
    return ans;
}
int Add_digit(int n) {
    while (n>=10) {
        n=Break_down(n);
    }
    return n;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<Add_digit(n);
}