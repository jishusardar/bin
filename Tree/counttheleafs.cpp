//count the no of leaf nodes int BST
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
    cout<<"Entre The Left Child of "<<x<<" :";
    root->left=BST();
    cout<<"Entre The Right Child of "<<x<<" :";
    root->right=BST();
    return root;
}
void countleaf(TreeNode* root,int &count) {
    if (!root)
        return;
    if (!root->left&&!root->right)
        count++;
    countleaf(root->left,count);
    countleaf(root->right,count);
}
// int countleaf(TreeNode* root) {
//     if (!root)
//         return 0;
//     if (!root->left&&!root->right)
//         return 1;
//     return 0+countleaf(root->left)+countleaf(root->right);
// }
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    int leaf=0;
    countleaf(root,leaf);
    cout<<"The No. Of Leaf Nodes in The BST is: "<<leaf;
}
