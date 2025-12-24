//
// Created by jishu on 23-07-2025.
//construct tree from inorder and preorder traversal
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
int position(vector<int>&in,vector<int>&pre,int start,int end,int val) {
    for (int i=start;i<=end;i++) {
        if(pre[i]==val)
        return i;
    }
    return -1;
}
TreeNode* ConstructTree(vector<int>&in,vector<int>&pre,int start,int end,int index) {
    if (start>end)
        return NULL;
    TreeNode* root=new TreeNode(pre[index]);
    int pos=position(in,pre,start,end,pre[index]);
    root->left=ConstructTree(in,pre,start,pos-1,index+1);
    root->right=ConstructTree(in,pre,pos+1,end,index+(pos-start)+1);
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
    vector<int>arr1(n);
    cout<<"Entre The Inorder: ";
    for (int i=0;i<n;i++)
        cin>>arr1[i];
    cout<<endl;
    vector<int>arr2(n);
    cout<<"Entre The preorder : ";
    for (int i=0;i<n;i++)
        cin>>arr2[i];
    TreeNode* root=ConstructTree(arr1,arr2,0,arr1.size()-1,0);
    preorder(root);
}
