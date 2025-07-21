//count the non leaf nodes
#include <algorithm>
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
TreeNode* BST() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=BST();
    cout<<"Entre The Right child of "<<x<<" : ";
    root->right=BST();
    return root;
}
int countnonleaf(TreeNode* root) {
    if (!root)
        return 0;
    if (!root->left&&!root->right)
        return 0;
    return 1+countnonleaf(root->left)+countnonleaf(root->right);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    cout<<"The No of Non Leaf Nodes are:"<<countnonleaf(root);
}
