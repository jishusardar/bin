//check the BST is balanced or not
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
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BST();
    return root;
}
int height(TreeNode* root,bool &valid) {
    if (!root)
        return 0;
    int l=height(root->left,valid);
    int r=height(root->right,valid);
    if (abs(l-r)>1)
        valid=0;
    return 1+max(height(root->left,valid),height(root->right,valid));
}
bool isBalanced(TreeNode* root) {
    bool valid=1;
    height(root,valid);
    return valid;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    if (isBalanced(root))
        cout<<"The BST is Balanced";
    else
        cout<<"The BST is Not Balanced";
}
