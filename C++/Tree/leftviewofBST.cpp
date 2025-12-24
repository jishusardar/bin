//left view of a BST
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
    cout<<"Entre The left child of "<<x<<" : ";
    root->left=BST();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BST();
    return root;
}
void leftviewofBST(TreeNode* root,vector<int>&ans,int level) {
    if (!root)
        return;
    if (ans.size()==level) {
        ans.push_back(root->data);
    }
        leftviewofBST(root->left,ans,level+1);
        leftviewofBST(root->right,ans,level+1);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    vector<int>ans;
    leftviewofBST(root,ans,0);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
