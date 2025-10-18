//
// Created by jishu on 17-10-2025.
//check it is a rectangle or not
#include <iostream>
using namespace std;
bool check_rectangle(int i,int j,int k,int l) {
    return i==j&&k==l||i==k&&j==l;
}
int main() {
    int i,j,k,l;
    cout<<"Entre The Number: ";
    cin>>i>>j>>k>>l;
    cout<<check_rectangle(i,j,k,l);
}