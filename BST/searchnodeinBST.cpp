//
// Created by jishu on 30-07-2025.
//search Node in a BST
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
bool searchnodeinBST(TreeNode* root,int target) {
    if (!root)
        return 0;
    if (root->data==target)
        return 1;
    return searchnodeinBST(root->left,target)||searchnodeinBST(root->right,target);
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
    int target;
    cout<<"Entre The Target: ";
    cin>>target;
    if (searchnodeinBST(root,target))
        cout<<"The Node is Present";
    else
        cout<<"The Node is Not Present";
}
