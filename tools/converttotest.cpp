//
// Created by jishu on 15-10-2025.
//

#include "converttotest.h"
#include<iostream>
using namespace std;
string convert(string s) {
    for (int i=0;i<s.size();i++) {
        if (s[i]=='[')
            s[i]='{';
        if (s[i]==']')
            s[i]='}';
    }
    return s;
}
int main() {
    string s;
    getline(cin,s);
    cout<<convert(s);
}
