//
// Created by jishu on 17-10-2025.
//check the number is power of two or not
#include<iostream>
using namespace std;
bool power_of_two(int n) {
    if (n<1)
        return 0;
    while (n!=1) {
        if (n%2)
            return 0;
        n/=2;
    }
    return 1;
}
int main() {
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<power_of_two(n);
}
