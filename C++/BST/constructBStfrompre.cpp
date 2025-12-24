//
// Created by jishu on 31-07-2025.
//construct a binary search tree from preorder traversal
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
TreeNode* constructfrompre(vector<int>&pre,int &index,int lower,int higher) {
    if (index==pre.size()||pre[index]<lower||pre[index]>higher)
        return NULL;
    TreeNode* root=new TreeNode(pre[index++]);
    root->left=constructfrompre(pre,index,lower,root->data);
    root->right=constructfrompre(pre,index,root->data,higher);
    return root;
}
void inorder(TreeNode* root) {
    if (!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int index=0;
    TreeNode* root=constructfrompre(arr,index,INT_MIN,INT_MAX);
    inorder(root);
}
