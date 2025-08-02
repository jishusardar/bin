//
// Created by jishu on 02-08-2025.
//fixing two nodes of BSt
#include <iostream>
#include <random>
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
void TwoNodesOFBST(TreeNode* root) {
    //first we will do inorder traversal using morris traversal
    // 4 5 [10 7] 8 [9 6]
    //     prob1    prob2
    //see clearly if we swap 10 and 6 then the order is getting corrected
    //first and second variable is for getting the fault in inorder traversal
    //contains exactly two misplaced nodes
    //last contains the node of the previous and present contains the present node value
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* last=NULL;
    TreeNode* present=NULL;
    while (root) {
        if (!root->left) {
            last=present;
            present=root;
            if (last&&last->data>present->data) {
                if (!first)
                    first=last;
                second=present;
            }
            root=root->right;
        }
        else{
            TreeNode* curr=root->left;
            while (curr->right&&curr->right!=root)
                curr=curr->right;
            if (!curr->right) {
                curr->right=root;
                root=root->left;
            }
            else {
                last=present;
                present=root;
                curr->right=NULL;
                if (last&&last->data>present->data) {
                    if (!first)
                        first=last;
                    second=present;
                }
                root=root->right;
            }
        }
    }
    swap(first->data,second->data);
}
void inorderTraversal(TreeNode* root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
TreeNode* CBST(){
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<": ";
    root->left=CBST();
    cout<<"Entre The Right Child of "<<x<<": ";
    root->right=CBST();
    return root;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=CBST();
    inorderTraversal(root);
    cout<<endl;
    TwoNodesOFBST(root);
    inorderTraversal(root);
}
