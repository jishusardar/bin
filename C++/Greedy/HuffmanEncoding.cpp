//
// Created by jishu on 09-01-2026.
//Huffman Encoding
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
class Tree {
public:
    int freq;
    char c;
    Tree* left;
    Tree* right;
    Tree(int freq,char c) {
        this->freq=freq;
        this->c=c;
        this->left=NULL;
        this->right=NULL;
    }
};
class comp {
public:
    int freq;
    bool operator()(Tree* a,Tree*b) {
        return a->freq>b->freq;
    }
};
void preorder(Tree* root,vector<string>&ans,string s) {
    if (!root)
        return;
    if (!root->left&&!root->right) {
        ans.push_back(s);
        return;
    }
    s.push_back('0');
    preorder(root->left,ans,s);
    s.pop_back();
    s.push_back('1');
    preorder(root->right,ans,s);
    s.pop_back();
}
vector<string> huffmanCodes(string S, vector<int> f, int N) {
    // Code here
    priority_queue<Tree*,vector<Tree*>,comp>pq;
    for (int i=0;i<N;i++) {
        pq.push(new Tree(f[i],S[i]));
    }
    while (pq.size()>1) {
        Tree* first=pq.top();
        pq.pop();
        Tree* second=pq.top();
        pq.pop();
        Tree* root=new Tree(first->freq+second->freq,'$');
        root->left=first;
        root->right=second;
        pq.push(root);
    }
    Tree* root=pq.top();
    pq.pop();
    string temp;
    vector<string>ans;
    preorder(root,ans,temp);
    return ans;
}
int main() {
    string s="abcdef";
    vector<int>f={5, 9, 12, 13, 16, 45};
    int N=6;
    vector<string>ans=huffmanCodes(s,f,N);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
