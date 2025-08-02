//
// Created by jishu on 31-07-2025.
//construct a binary search from postorder Traversal
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
TreeNode* constructTree(vector<int>&post,int &index,int lower,int higher) {
    if (index==-1||post[index]<lower||post[index]>higher)
        return NULL;
    TreeNode* root=new TreeNode(post[index--]);
    root->right=constructTree(post,index,root->data,higher);
    root->left=constructTree(post,index,lower,root->data);
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
    int index=arr.size()-1;
    TreeNode* root=constructTree(arr,index,INT_MIN,INT_MAX);
    inorder(root);
}
