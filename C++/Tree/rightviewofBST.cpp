//
// Created by jishu on 23-07-2025.
//
//right view of BST
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
TreeNode* BST() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=BST();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BST();
    return root;
}
void Rightview(TreeNode* root,vector<int>&ans,int i) {
    if (!root)
        return;
    if (i==ans.size()) {
        ans.push_back(root->data);
    }
    Rightview(root->right,ans,i+1);
    Rightview(root->left,ans,i+1);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    vector<int>ans;
    Rightview(root,ans,0);
    cout<<"Right View of A BST is : ";
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
