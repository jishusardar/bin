//
// Created by jishu on 01-08-2025.
//sorted Linked list To Binary Search Tree
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
void traverse(TreeNode* root) {
    if (!root)
        return;
    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}
TreeNode* LLconstruct(vector<int>&arr,int i) {
    if (i==arr.size())
        return NULL;
    TreeNode* root=new TreeNode(arr[i]);
    root->right=LLconstruct(arr,i+1);
    return root;
}
TreeNode* ConstructTree(vector<TreeNode*>&num,int start,int end) {
    if (start>end)
        return NULL;
    int mid=start+(end-start)/2;
    TreeNode* root=num[mid];
    root->left=ConstructTree(num,start,mid-1);
    root->right=ConstructTree(num,mid+1,end);
    return root;
}
TreeNode* LLtoBST(TreeNode* root) {
    vector<TreeNode*>arr;
    while (root) {
        arr.push_back(root);
        root=root->right;
    }
    return ConstructTree(arr,0,arr.size()-1);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    TreeNode* root=LLconstruct(arr,0);
    root=LLtoBST(root);
    traverse(root);
}
