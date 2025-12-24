//
// Created by jishu on 27-08-2025.
//minimum window substring
#include <iostream>
#include <vector>
using namespace std;
string minimumwindowsubstr(string s,string t) {
    vector<int>count(256,0);
    for (int i=0;i<t.size();i++) {
        count[t[i]]++;
    }
    int start=0,end=0,total=t.size(),index=-1;
    int len=s.size();
    while (end<s.size()) {
        count[s[end]]--;
        if (count[s[end]]>=0)
            total--;
        while (!total&&start<=end) {
            if (len>(end-start+1)) {
                len=end-start+1;
                index=start;
            }
            count[s[start]]++;
            if (count[s[start]]>0)
                total++;
            start++;
        }
        end++;
    }
    if (index==-1)
        return " ";
    string str="";
    for (int i=index;i<=index+len;i++) {
        str+=s[i];
    }
    return str;
}
int main() {
    string s,t;
    cout<<"Entre The String 1: ";
    cin>>s;
    cout<<"Entre The String 2: ";
    cin>>t;
    cout<<"The Minimum Window Substring is : "<<minimumwindowsubstr(s,t);
}
