//
// Created by jishu on 15-08-2025.
//is Binary Tree is Heap
//check this Trees is maxheap or not
#include <iostream>
using namespace std;
//create Tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
TreeNode* CreateBT() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<root->data<<" : ";
    root->left=CreateBT();
    cout<<"Entre The Right Child of "<<root->data<<" : ";
    root->right=CreateBT();
    return root;
}
bool CBT(TreeNode* root,int index,int n) {
    if (!root)
        return 1;
    if (index>=n)
        return 0;
    return CBT(root->left,2*index+1,n)&&CBT(root->right,2*index+2,n);
}
int count(TreeNode* root) {
    if (!root)
        return 0;
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return 1+leftcount+rightcount;
}
bool checkmaxHeap(TreeNode* root) {
    if (root->left) {
        if (root->data<root->left->data)
            return 0;
        if (!checkmaxHeap(root->left))
            return 0;
    }
    if (root->right) {
        if (root->data<root->right->data)
            return 0;
        return checkmaxHeap(root->right);
    }
    return 1;
}
bool IsBTHeap(TreeNode* root) {
 //Heap means
    //CBT then maxheap parent>=children
    //first CBT
    int totalnodes=count(root);
    if (!CBT(root,0,totalnodes))
        return 0;
    //we checked CBT now we check the maxheap property
    return checkmaxHeap(root);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=CreateBT();
    if (IsBTHeap(root))
        cout<<"The BST is a Heap";
    else
        cout<<"The BST Is Not a Heap";
}
