//
// Created by jishu on 09-01-2026.
//task scheduler
#include<iostream>
#include <vector>
using namespace std;
int taskscheduler(string tasks,int n) {
    vector<int>count(26,0);
    for (int i=0;i<tasks.size();i++) {
        count[tasks[i]-'A']++;
    }
    int maxcount=0;
    for (int i=0;i<26;i++) {
        maxcount=max(count[i],maxcount);
    }
    int maxsum=0;
    for (int i=0;i<26;i++) {
        if (count[i]==maxcount)
            maxsum++;
    }
    int ans=(maxcount-1)*(n+1)+maxsum;
    return ans<tasks.size()?tasks.size():ans;
}
int main() {
    string s;
    int n;
}
