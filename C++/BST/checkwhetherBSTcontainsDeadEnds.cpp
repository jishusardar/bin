//
// Created by jishu on 01-08-2025.
//check whether BST Conatins Dead Ends
//means no other node can be inserted into the tree
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
TreeNode* CBST(TreeNode* root,int val) {
    if (!root) {
        root=new TreeNode(val);
        return root;
    }
    if (root->data>val)
        root->left=CBST(root->left,val);
    else
        root->right=CBST(root->right,val);
    return root;
}
//Method 1
// bool traverse(TreeNode* root,int lower,int upper) {
//     if (!root)
//         return 0;
//     if (!root->left&&!root->right) {
//         if (root->data-lower==1&&upper-root->data==1)
//             return 1;
//     }
//     return traverse(root->left,lower,root->data)||traverse(root->right,root->data,upper);
// }
//Method 2
void traverse(TreeNode* root,int lower,int upper,bool &ans) {
    if (!root)
        return;
    if (!root->left&&!root->right) {
        if (root->data-lower==1&&upper-root->data==1)
            ans=1;
    }
    traverse(root->left,lower,root->data,ans);
    traverse(root->right,root->data,upper,ans);
}
bool isContainDeadEnd(TreeNode* root) {
    bool ans=0;
    traverse(root,0,INT_MAX,ans);
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root=NULL;
    for (int i=0;i<n;i++)
        root=CBST(root,arr[i]);
    if (isContainDeadEnd(root))
        cout<<"The Tree Contains Dead Ends";
    else
        cout<<"The Tree Doesn't Contain Dead Ends";
}
