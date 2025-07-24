//
// Created by jishu on 24-07-2025.
//preorder traversal by morris traversal
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
TreeNode* BT() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The left Element of "<<x<<" : ";
    root->left=BT();
    cout<<"Entre The right Element of "<<x<<" : ";
    root->right=BT();
    return root;
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    while (root) {
        ans.push_back(root->data);
        if (root->left) {
            TreeNode* curr=root->left;
            while (curr->right) {
                curr=curr->right;
            }
            if (!curr->right) {
                if (root->right)
                curr->right=root->right;
                root=root->left;
            }
            else {
                root=root->right;
            }
        }
        else {
            root=root->right;
        }
    }
    return ans;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    vector<int>ans=preorderTraversal(root);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
