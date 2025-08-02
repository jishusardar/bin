//
// Created by jishu on 30-07-2025.
//inorder sucessor in BST
//means the 1st largest element than target
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
TreeNode* CreateTree(TreeNode* root,int val) {
    if (!root) {
        root=new TreeNode(val);
        return root;
    }
    if (root->data>val)
        root->left=CreateTree(root->left,val);
    else
        root->right=CreateTree(root->right,val);
    return root;
}
void traversal(TreeNode* root,int target,int &ans) {
    if (!root)
        return;
    traversal(root->right,target,ans);
    if (root->data>target)
        ans=root->data;
    traversal(root->left,target,ans);
}
int inorderSucessor(TreeNode* root,int target) {
    int ans=-1;
    traversal(root,target,ans);
    return ans;
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
        root=CreateTree(root,arr[i]);
    int target;
    cout<<"Entre The Target Element: ";
    cin>>target;
    cout<<"Inorder Sucessor in BST is: "<<inorderSucessor(root,target);
}
