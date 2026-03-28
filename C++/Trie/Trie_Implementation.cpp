//trie implementation
#include<iostream>
using namespace std;
class TrieNode {
public:
    TrieNode* child[26];
    bool isEndOfWorld;
    TrieNode() {
        isEndOfWorld=0;
        for (int i=0;i<26;i++)
            child[i]=NULL;
    }
};
class Trie {
    TrieNode* root;
    bool isEmpty(TrieNode* root) {
        for (int i=0;i<26;i++) {
            if (root->child[i])
                return 0;
        }
        return 1;
    }
public:
    Trie() {
        root=new TrieNode();
    }
    void insert(string word) {
        TrieNode* node=root;
        for (int i=0;i<word.size();i++) {
            int index=word[i]-'a';
            if (node->child[index]==NULL)
                node->child[index]=new TrieNode();
            node=node->child[index];
        }
        node->isEndOfWorld=1;
    }
    bool SearchElement(string word) {
        TrieNode* node=root;
        for (char c:word) {
            int index=c-'a';
            if (node->child[index]==NULL)
                return 0;
            node=node->child[index];
        }
        return node->isEndOfWorld;
    }
    // bool isEmpty(TrieNode* node) {
    //     for (int i=0;i<26;i++) {
    //         if (node->child[i])
    //             return 0;
    //     }
    //     return 1;
    // }
    // bool Deletee(TrieNode* node,string word,int depth) {
    //     if (depth==word.size()) {
    //         //check if the word exist
    //         if (!node->isEndOfWorld)
    //             return 0;
    //         node->isEndOfWorld=0;
    //         return isEmpty(node);
    //     }
    //     //agar word exist hi nahi karta
    //     int index=word[depth]-'a';
    //     if (node->child[index]==NULL)
    //         return 0;
    //     bool shouldDelete=Deletee(node->child[index],word,depth+1);
    //     if (shouldDelete) {
    //         delete node->child[index];
    //         node->child[index]=NULL;
    //         return isEmpty(node)&&!node->isEndOfWorld;
    //     }
    //     return 0;
    // }
    // void DeleteWord(string word) {
    //     Deletee(root,word,0);
    // }
    bool Deletee(TrieNode* node,string word,int depth) {
        if (depth==word.size()) {
            if (!node->isEndOfWorld)
                return 0;
            node->isEndOfWorld=0;
            return isEmpty(node);
        }
        int index=word[depth]-'a';
        if (node->child[index]==NULL)
            return 0;
        bool ShouldDelete=Deletee(node->child[index],word,depth+1);
        if (ShouldDelete) {
            delete node->child[index];
            node->child[index]=NULL;
            return !node->isEndOfWorld&&isEmpty(node);
        }
        return 0;
    }
    void Deleteword(string word) {
        Deletee(root,word,0);
    }
};
int main() {
    Trie* root=new Trie();
    root->insert("apple");
    root->insert("apex");
    root->insert("almond");
    root->insert("money");
    root->insert("mon");
    root->Deleteword("mon");
    cout<<root->SearchElement("money");
}
