//size of tree
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
    cout<<"Entre The left child of "<<x<<" :";
    root->left=BST();
    cout<<"Entre The Right Child of "<<x<<" :";
    root->right=BST();
    return root;
}
int height(TreeNode* root) {
    if (!root)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    cout<<"The Height of The BST is: "<<height(root);
}
