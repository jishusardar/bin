//
// Created by jishu on 30-07-2025.
//array to balanced binary search tree and asked for returning the root
// #include <iostream>
// #include <vector>
// using namespace std;
//
// class TreeNode {
// public:
//     int data;
//     TreeNode *left;
//     TreeNode *right;
//
//     TreeNode(int data) {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// TreeNode* ConstructBalBST(vector<int>arr,int start,int end) {
//     if (start>end)
//         return NULL;
//     int mid=start+(end-start)/2;
//     TreeNode* root=new TreeNode(arr[mid]);
//     root->left=ConstructBalBST(arr,start,mid-1);
//     root->right=ConstructBalBST(arr,mid+1,end);
//     return root;
// }
// void preorder(TreeNode* root) {
//     if (!root)
//         return;
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }
// int main() {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     cout<<"Entre The Elements: ";
//     for (int i=0;i<n;i++)
//         cin>>arr[i];
//     TreeNode* root=ConstructBalBST(arr,0,n-1);
//     preorder(root);
// }
//array given construct a BST and return preorder vector
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
void BSTPreorder(vector<int>&arr,int start,int end,vector<int>&ans) {
    if (start>end)
        return;
    int mid=start+(end-start)/2;
    ans.push_back(arr[mid]);
    BSTPreorder(arr,start,mid-1,ans);
    BSTPreorder(arr,mid+1,end,ans);
}
vector<int>arrayToPreBST(vector<int>&arr) {
    vector<int>ans;
    BSTPreorder(arr,0,arr.size()-1,ans);
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
    vector<int>ans=arrayToPreBST(arr);
    cout<<"The Preorder Of The BST: ";
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
