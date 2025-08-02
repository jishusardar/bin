//
// Created by jishu on 31-07-2025.
//lowest common ancestor in a BST
#include <iostream>
#include <vector>
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
TreeNode* LowestCommonAncestor(TreeNode* root,int p,int q) {
    if (!root)
        return NULL;
    if (root->data<p&&root->data<q)
        return LowestCommonAncestor(root->left,p,q);
    else if (root->data>p&&root->data>q)
        return LowestCommonAncestor(root->right,p,q);
    else
        return root;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root=NULL;
    for (int i=0;i<n;i++)
        root=CBST(root,arr[i]);
    int p,q;
    cout<<"Entre The Elements P and Q: ";
    cin>>p>>q;
    cout<<"Common Ancestor of the p and q is : "<<LowestCommonAncestor(root,p,q)->data;
}
