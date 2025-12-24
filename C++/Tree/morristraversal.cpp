//
// Created by jishu on 24-07-2025.
//morris traversal
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
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=BT();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BT();
    return root;
}
vector<int> Traverse(TreeNode* root) {
    vector<int>ans;
    while (root) {
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
                ans.push_back(root->data);
                root=root->right;
            }
        }
        else {
            ans.push_back(root->data);
            root=root->right;
        }
    }
    return ans;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    vector<int>ans=Traverse(root);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
