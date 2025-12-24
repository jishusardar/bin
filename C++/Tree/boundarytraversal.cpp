//
// Created by jishu on 24-07-2025.
//boundary traversal
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
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
TreeNode* BT() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=BT();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BT();
    return root;
}
void leftmost(TreeNode* root,vector<int>&ans) {
    if (!root->left&&!root->right) {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    leftmost(root->left,ans);
    else if (root->right)
        leftmost(root->right,ans);
}
void rightmost(TreeNode* root,vector<int>&ans) {
    if (!root->left&&!root->right)
        return;
    ans.push_back(root->data);
    if (root->right)
        rightmost(root->right,ans);
    else if (root->left)
        rightmost(root->left,ans);
}
void Traverse(TreeNode* root,vector<int>&ans) {
    if (!root)
        return;
    if (!root->left&&!root->right)
    ans.push_back(root->data);
    Traverse(root->left,ans);
    Traverse(root->right,ans);
}
vector<int> BoundaryTraversal(TreeNode* root) {
    vector<int>ans;
    ans.push_back(root->data);
    if (root->left)
    leftmost(root->left,ans);
    if (root->left||root->right)
    Traverse(root,ans);
    //the most element are have to be in reverse order
    if (root->right) {
        vector<int>temp;
        rightmost(root->right,temp);
        for (int i=temp.size()-1;i>=0;i--)
            ans.push_back(temp[i]);
    }
    return ans;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    vector<int>ans=BoundaryTraversal(root);
    cout<<endl;
    cout<<"The Boundary Elements: ";
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
