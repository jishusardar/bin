//
// Created by jishu on 25-07-2025.
//flatten binary to linkedlist
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
void Flatten(TreeNode* root) {
    while (root) {
        if (root->left) {
            TreeNode* curr=root->left;
            TreeNode* ptr=curr;
            while (curr->right)
                curr=curr->right;
            if (!curr->right) {
                if (root->right)
                    curr->right=root->right;
                root->right=ptr;
                //and have to delete root->left
                root->left=NULL;
            }
            root=root->right;
        }
        else
            root=root->right;
    }
}
void Traverse(TreeNode* root) {
    if (!root)
        return;
    cout<<root->data<<" ";
    Traverse(root->right);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    Flatten(root);
    Traverse(root);
}
