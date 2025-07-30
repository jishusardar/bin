//
// Created by jishu on 30-07-2025.
//check for BSt
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
TreeNode* CBST() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=CBST();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=CBST();
    return root;
}
void check(TreeNode* root,int &ans,bool &p) {
    if (!root)
        return;
    check(root->left,ans,p);
    if (ans>root->data)
        p=0;
    ans=root->data;
    check(root->right,ans,p);
}
bool BSTcheck(TreeNode* root) {
    bool p=1;
    int ans=INT_MIN;
    check(root,ans,p);
    return p;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=CBST();
    if (BSTcheck(root))
        cout<<"The Tree is BST";
    else
        cout<<"The Tree is Not BST";
}