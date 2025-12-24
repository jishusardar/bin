//
// Created by jishu on 17-10-2025.
//Bishop Moves
#include<iostream>
using namespace std;
int Bishop_Moves(int i,int j) {
    return min(i-1,j-1)+min(8-i,j-1)+min(i-1,8-j)+min(8-i,8-j);
}
int main() {
    int n,m;
    cout<<"Entre The pos: ";
    cin>>n>>m;
    cout<<Bishop_Moves(n,m);
}
