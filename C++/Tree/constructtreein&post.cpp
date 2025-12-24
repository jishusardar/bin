//
// Created by jishu on 23-07-2025.
// construct Binary Tree from inorder and postorder
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
int position(vector<int>&in,vector<int>&post,int start,int end,int val) {
    for (int i=start;i<=end;i++) {
        if (in[i]==val)
            return i;
    }
    return -1;
}
TreeNode* constructTree(vector<int>&in,vector<int>&post,int start,int end,int index) {
    if (start>end)
        return NULL;
    TreeNode* root=new TreeNode(post[index]);
    int pos=position(in,post,start,end,post[index]);
    root->right=constructTree(in,post,pos+1,end,index-1);
    root->left=constructTree(in,post,start,pos-1,index-(end-pos)-1);
    return root;
}
void postorder(TreeNode* root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr1(n);
    cout<<"Entre The inorder: ";
    for (int i=0;i<n;i++)
        cin>>arr1[i];
    vector<int>arr2(n);
    cout<<"Entre The post order: ";
    for (int i=0;i<n;i++)
        cin>>arr2[i];
    TreeNode* root=constructTree(arr1,arr2,0,n-1,n-1);
    postorder(root);
}
