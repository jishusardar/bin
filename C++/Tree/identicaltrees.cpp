//check the trees are identical or not
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
bool identicaltrees(TreeNode* root1,TreeNode* root2) {
    if (!root1&&!root2)
        return 1;
    if (!(root1&&root2))
        return 0;
    if (root1->data!=root2->data)
        return 1;
    return identicaltrees(root1->left,root2->left)&&identicaltrees(root1->right,root2->right);
}
int main() {
    cout<<"Entre The Root Element1: ";
    TreeNode* root1=BST();
    cout<<"Entre The root element2: ";
    TreeNode* root2=BST();
    if (identicaltrees(root1,root2))
        cout<<"The Trees are Identical";
    else
        cout<<"The Trees are not Identical";
}
