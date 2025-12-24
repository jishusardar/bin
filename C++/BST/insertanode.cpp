//
// Created by jishu on 29-07-2025.
//insert a node in Tree
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
TreeNode* insertNode(TreeNode* root,int val) {
    if (!root) {
        root=new TreeNode(val);
        return root;
    }
    if (root->data>val)
        root->left=insertNode(root->left,val);
    else
        root->right=insertNode(root->right,val);
    return root;
}
void preorder(TreeNode* root) {
    if (!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root=NULL;
    for (int i=0;i<n;i++)
        root=CBST(root,arr[i]);
    cout<<"Entre The insert Node: ";
    int x;
    cin>>x;
    root=insertNode(root,x);
    preorder(root);
}