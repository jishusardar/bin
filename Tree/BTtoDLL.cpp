//
// Created by jishu on 25-07-2025.
// Binary Tree To Doubly Linked List
#include <codecvt>
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
TreeNode* Transform(TreeNode* root) {
    TreeNode* ans=new TreeNode(0);
    TreeNode* prev=ans;
    while (root){
        if (root->left) {
            TreeNode* curr=root->left;
            while (curr->right&&curr->right!=root) {
                curr=curr->right;
            }
            if (!curr->right) {
                curr->right=root;
                root=root->left;
            }
            else {
                curr->right=NULL;
                prev->right=root;
                root->left=prev;
                prev=root;
                root=root->right;
            }
        }
        else{
            prev->right=root;
            root->left=prev;
            prev=root;
            root=root->right;
        }
    }
    ans=ans->right;
    ans->left=NULL;
    return ans;
}
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
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    root=Transform(root);
    for (TreeNode* i=root;i!=NULL;i=i->right)
        cout<<i->data<<" ";
}
