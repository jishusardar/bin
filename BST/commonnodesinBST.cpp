//
// Created by jishu on 01-08-2025.
//common nodes in BST
#include <functional>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode* CBST(TreeNode* root,int val) {
    if (!root) {
        root=new TreeNode(val);
        return root;
    }
    if (root->data>val)
        root->left=CBST(root->left,val);
    else
        root->right=CBST(root->right,val);
    return root;
}
vector<int> CommonNodesinBST(TreeNode* root1,TreeNode* root2) {
    vector<int>ans;
    stack<TreeNode*>s1,s2;
    while (root1) {
        s1.push(root1);
        root1=root1->left;
    }
    while (root2) {
        s2.push(root2);
        root2=root2->left;
    }
    while (!s1.empty()&&!s2.empty()) {
        if (s1.top()->data==s2.top()->data) {
            ans.push_back(s1.top()->data);
            root1=s1.top()->right;
            root2=s2.top()->right;
            s1.pop();
            s2.pop();
        }
        else if (s1.top()->data>s2.top()->data) {
            root2=s2.top()->right;
            s2.pop();
        }
        else {
            root1=s1.top()->right;
            s1.pop();
        }
        while (root1) {
            s1.push(root1);
            root1=root1->left;
        }
        while (root2) {
            s2.push(root2);
            root2=root2->left;
        }
    }
    return ans;
}
int main() {
    int n,m;
    cout<<"Entre The Size1: ";
    cin>>n;
    cout<<"Entre The Size2: ";
    cin>>m;
    vector<int>arr(n);
    vector<int>arg(m);
    cout<<"Entre The Elements 1: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root1=NULL;
    for (int i=0;i<n;i++)
        root1=CBST(root1,arr[i]);
    cout<<"Entre The Elements 2: ";
    TreeNode* root2=NULL;
    for (int i=0;i<m;i++)
        cin>>arg[i];
    for (int i=0;i<m;i++)
        root2=CBST(root2,arg[i]);
    vector<int>ans=CommonNodesinBST(root1,root2);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
