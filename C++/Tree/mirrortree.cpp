//given a tree make it an mirror of the tree
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
void preorder(TreeNode* root) {
    if (!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// void MirrorTree(TreeNode* root) {
//     if (!root)
//         return;
//     swap(root->left,root->right);
//     MirrorTree(root->left);
//     MirrorTree(root->right);
// }
//inverted mirror tree
void MirrorTree(TreeNode* root) {
    if (!root)
        return;
    TreeNode* temp=root->right;
    root->right=root->left;
    root->left=temp;
    MirrorTree(root->left);
    MirrorTree(root->right);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    cout<<"Preorder Before Mirror : ";
    preorder(root);
    cout<<endl;
    MirrorTree(root);
    cout<<"Preorder After Mirror: ";
    preorder(root);
    cout<<endl;
}
