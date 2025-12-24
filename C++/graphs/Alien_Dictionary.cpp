//
// Created by jishu on 20-09-2025.
//Alien Dictionary
#include<iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
string findOrder(vector<string>&words) {
    unordered_map<char,unordered_set<char>>Adj;
    for (int i=0;i<words.size()-1;i++) {
        string s1=words[i],s2=words[i+1];
        int j=0,k=0;
        while (j<s1.size()&&k<s2.size()&&s1[j]==s2[k]) {
            j++,k++;
        }
        if (j==s1.size())
            continue;
        if (k==s2.size())
            return "";
        Adj[s1[j]].insert(s2[k]);
    }
    int count=0;
    vector<int>indegree(26,-1);
    for (int i=0;i<words.size();i++) {
        for (int j=0;j<words[i].size();j++) {
            if (indegree[words[i][j]-'a']==-1)
                count++;
                indegree[words[i][j]-'a']=0;
        }
    }
    for (auto i:Adj) {
        for (auto j:i.second) {
            indegree[j-'a']++;
        }
    }
    queue<char>q;
    for (int i=0;i<26;i++) {
        if (!indegree[i]) {
            char c='a'+i;
            q.push(c);
        }
    }
    string ans="";
    while (!q.empty()) {
        char node=q.front();
        q.pop();
        ans+=node;
        for (auto i:Adj[node]) {
            indegree[i-'a']--;
            if (indegree[i-'a']==0)
                q.push(i);
        }
    }
    return ans.size()==count?ans:"";
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<string>words(n);
    for (int i=0;i<n;i++) {
        cout<<"Entre the Elements: ";
        cin>>words[i];
    }
    cout<<findOrder(words);
}
