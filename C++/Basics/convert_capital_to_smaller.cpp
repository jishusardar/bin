//
// Created by jishu on 17-10-2025.
//convert smaller letter into capital letter
#include<iostream>
using namespace std;
char convert(char c) {
    int n=c-'a';
    if (n<0||n>26)
        return '@';
    return char('A'+n);
}
int main() {
    char c;
    cout<<"Entre The Char: ";
    cin>>c;
    cout<<convert(c);
}
