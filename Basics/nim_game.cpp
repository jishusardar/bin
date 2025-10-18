//
// Created by jishu on 18-10-2025.
//nim game
#include<iostream>
using namespace std;
bool can_win_game(int n) {
    if (!(n%4))
        return 1;
    return 0;
}
int main() {
    int n;
    cout<<"Entre The Number U start With: ";
    cin>>n;
    cout<<can_win_game(n);
}
