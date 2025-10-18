//
// Created by jishu on 17-10-2025.
//compliment_of_a_no
#include<iostream>
using namespace std;
int compliment_of_a_no(int n) {
    int temp=n,ans=0,mul=1;
    while (temp!=0) {
        int rem=temp%2;
        temp/=2;
        rem^=1;
        ans+=rem*mul;
        mul*=2;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<compliment_of_a_no(n);
}
