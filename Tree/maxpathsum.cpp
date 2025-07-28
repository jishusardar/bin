//
// Created by jishu on 28-07-2025.
//max path sum between two nodes
#include <iostream>
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
int sums(TreeNode* root,int &ans) {
    if (!root)
        return 0;
    if (!root->left&&!root->right)
        return root->data;
    ans=max(ans,root->data+sums(root->left,ans)+sums(root->right,ans));
    if (root->left&&root->right)
        return root->data+max(sums(root->left,ans),sums(root->right,ans));
    else if (root->left)
        return root->data+sums(root->left,ans);
    else
        return root->data+sums(root->right,ans);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    int ans=INT_MIN;
    int temp=sums(root,ans);
    if (ans!=INT_MIN)
        cout<<"The Max Sum of Paths between two Nodes "<<ans;
    else
        cout<<"The Max Sum of Paths between two Nodes "<<temp;
}
