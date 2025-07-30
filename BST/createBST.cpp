//
// Created by jishu on 29-07-2025.
//
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
TreeNode* CBST(TreeNode* root,int el) {
    if (!root) {
        root=new TreeNode(el);
        return root;
    }
    if (root->data>el)
        root->left=CBST(root->left,el);
    else
        root->right=CBST(root->right,el);
    return root;
}
void Traversal(TreeNode* root) {
    if (!root)
        return;
    Traversal(root->left);
    cout<<root->data<<" ";
    Traversal(root->right);
}
int main(){
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
    Traversal(root);
}