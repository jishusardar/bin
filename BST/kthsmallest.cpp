//
// Created by jishu on 29-07-2025.
//
//kth smallest element
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
TreeNode* CBST(TreeNode* root,int element) {
    if (!root) {
        root=new TreeNode(element);
        return root;
    }
    if (root->data>element)
        root->left=CBST(root->left,element);
    else
        root->right=CBST(root->right,element);
    return root;
}
void Traversal(TreeNode* root,int &ans) {
    if (!root)
        return;
    Traversal(root->left,ans);
    if (ans==-1) {
        ans=root->data;
    }
    Traversal(root->right,ans);
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
    int ans=-1;
    Traversal(root,ans);
    cout<<"The Minimum Element is : "<<ans;
}
