//Sum of Bst
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
    cout<<"Entre The left Child of "<<x<<": ";
    root->left=BST();
    cout<<"Entre The Right Child of "<<x<<": ";
    root->right=BST();
    return root;
}
int sumofBST(TreeNode* root) {
    if (!root)
        return 0;
    return root->data+sumofBST(root->left)+sumofBST(root->right);
}
void sumofBST(TreeNode* root,int &sum) {
    if (!root)
        return;
    sum+=root->data;
    sumofBST(root->left,sum);
    sumofBST(root->right,sum);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    int sum=0;
    sumofBST(root,sum);
    cout<<"Sum of BST is"<<sum;
}
