//
// Created by jishu on 17-10-2025.
//Detect The Year is Leap year or not
#include<iostream>
using namespace std;
bool isLeapYear(int n) {
    if (!(n%400))
        return 1;
    else if (n%100&&!(n%4))
        return 1;
    return 0;
}
int main() {
    int n;
    cout<<"Entre The Year:";
    cin>>n;
    cout<<isLeapYear(n);
}
