//
// Created by jishu on 28-07-2025.
//Burning Tree Problem
//a tree starts to burn from a target node that is given we have to find out  the total time needed to burn down the whole tree
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
TreeNode* BT() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The left Element of "<<x<<" : ";
    root->left=BT();
    cout<<"Entre The right Element of "<<x<<" : ";
    root->right=BT();
    return root;
}
int BurningTree(TreeNode*root,int target,int &time) {
    if (!root)
        return 0;
    if (root->data==target)
        return -1;
    int left=BurningTree(root->left,target,time);
    int right=BurningTree(root->right,target,time);
    if (left<0) {
        time=max(time,abs(left)+right);
        return left-1;
    }
    if (right<0) {
        time=max(time,abs(right)+left);
        return right-1;
    }
    return 1+max(left,right);
}
int height(TreeNode* root) {
    if (!root)
        return 0;
    return 1+max(height(root->right),height(root->left));
}
void findroot(TreeNode* root,int target,TreeNode* nroot) {
    if (!root)
        return;
    if (root->data==target)
        nroot=root;
    findroot(root->left,target,nroot);
    findroot(root->right,target,nroot);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    int target;
    cout<<"Entre The Target Node: ";
    cin>>target;
    int time=0;
    BurningTree(root,target,time);
    TreeNode* temp=NULL;
    findroot(root,target,temp);
    int ans=height(temp);
    cout<<"The Burning Tree Needed Time For Burn Completely: "<<max(time,ans);
}
