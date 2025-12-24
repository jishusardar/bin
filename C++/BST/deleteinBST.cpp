//
// Created by jishu on 30-07-2025.
//Delete a Node BST
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
TreeNode* CBST(TreeNode* root,int val) {
    if (!root) {
        root=new TreeNode(val);
        return root;
    }
    if (root->data>val)
        root->left=CBST(root->left,val);
    else
        root->right=CBST(root->right,val);
    return root;
}
TreeNode* DeleteinBST(TreeNode* root,int target) {
    if (!root)
        return NULL;
    if (root->data>target)
        root->left=DeleteinBST(root->left,target);
    else if (root->data<target)
        root->right=DeleteinBST(root->right,target);
    else {
        if (!root->left&&!root->right) {
            delete root;
            return NULL;
        }
        else if (!root->right) {
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        else if (!root->left) {
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        else {
            //find the grater element in left side of the root
            //to find the greatest element in left side we have to iterate through the right sideof the root left
            //we also can do like smallest on right side of the root
            TreeNode* curr=root->left;
            TreeNode* parent=root;
            while (curr->right) {
                parent=curr;
                curr=curr->right;
            }
            if (parent!=root) {
                parent->right=root->left;
                curr->left=root->left;
                curr->right=root->right;
                delete root;
                return curr;
            }
            else {
                parent->right=root->right;
                delete root;
                return curr;
            }
        }
    }
    return root;
}
void Traverse(TreeNode* root) {
    if (!root)
        return;
    Traverse(root->left);
    cout<<root->data<<" ";
    Traverse(root->right);
}
int main() {
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root=NULL;
    for (int i=0;i<n;i++)
        root=CBST(root,arr[i]);
    Traverse(root);
    cout<<endl;
    int target;
    cout<<"Entre The Eleemnt to Delete ";
    cin>>target;
    root=DeleteinBST(root,target);
    Traverse(root);
}
