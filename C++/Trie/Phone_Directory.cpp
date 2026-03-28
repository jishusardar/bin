// Created by jishu on 28-03-2026.
//Phone Directory
#include<iostream>
#include <vector>
using namespace std;
class TrieNode {
public:
    TrieNode* child[26];
    bool isEndofWord;
    TrieNode() {
        isEndofWord=0;
        for (int i=0;i<26;i++)
            child[i]=NULL;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    void insert(string word) {
        TrieNode* node=root;
        for (char c:word) {
            int index=c-'a';
            if (node->child[index]==NULL)
                node->child[index]=new TrieNode();
            node=node->child[index];
        }
        node->isEndofWord=1;
    }
    void findcontacts(TrieNode* root,string word,vector<string>&temp) {
        if (root->isEndofWord)
            temp.push_back(word);
        for (char c='a';c<='z';c++) {
            int index=c-'a';
            if (root->child[index])
                findcontacts(root->child[index],word+c,temp);
        }
    }
    vector<string>searchcontact(string word) {
        TrieNode* node=root;
        for (char c:word) {
            int index=c-'a';
            if (node->child[index]==NULL)
                return{"0"};
            node=node->child[index];
        }
        vector<string>temp;
        findcontacts(node,word,temp);
        return temp;
    }
};
vector<vector<string>> DislayContact(int n,string contact[],string s) {
    Trie* root=new Trie();
    for (int i=0;i<n;i++)
        root->insert(contact[i]);
    vector<vector<string>>ans;
    string prefix="";
    for (int i=0;i<s.size();i++) {
        prefix+=s[i];
        vector<string>temp=root->searchcontact(prefix);
        ans.push_back(temp);
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    string contacts[n];
    cout<<"Entre The strings: ";
    for (int i=0;i<n;i++) {
        cin>>contacts[i];
    }
    string s;
    cout<<"Entre The Prefix: ";
    cin>>s;
    vector<vector<string>>ans=DislayContact(n,contacts,s);
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
