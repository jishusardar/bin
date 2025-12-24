//
// Created by jishu on 03-08-2025.
//maximum sum BST in BST
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
class Box {
public:
    bool BST;
    int sum;
    int min;
    int max;
    Box(int data) {
        BST=1;
        sum=data;
        min=data;
        max=data;
    }
};
Box* find(TreeNode* root,int &sum) {
    if (!root->left&&!root->right) {
        Box* head=new Box(root->data);
        sum=max(sum,head->sum);
        return head;
    }
    else if (root->right&&!root->left) {
        Box* righthead=find(root->right,sum);
        if (righthead->BST&&righthead->min>root->data) {
            Box* head=new Box(root->data);
            head->sum+=righthead->sum;
            sum=max(sum,head->sum);
            head->max=righthead->max;
            return head;
        }
        else {
            righthead->BST=0;
            return righthead;
        }
    }
    else if (root->left&&!root->right) {
        Box* lefthead=find(root->left,sum);
        if (lefthead->BST&&lefthead->max<root->data) {
            Box* head=new Box(root->data);
            head->sum+=lefthead->sum;
            sum=max(sum,head->sum);
            head->min=lefthead->min;
            return head;
        }
        else {
            lefthead->BST=0;
            return lefthead;
        }
    }
    else {
        Box* lefthead=find(root->left,sum);
        Box* righthead=find(root->right,sum);
        if (lefthead->BST&&righthead->BST&&lefthead->max<root->data&&righthead->min>root->data) {
            Box* head=new Box(root->data);
            head->sum+=lefthead->sum+righthead->sum;
            sum=max(sum,head->sum);
            head->min=lefthead->min;
            head->max=righthead->max;
            return head;
        }
        else {
            lefthead->BST=0;
            return lefthead;
        }
    }
}
int MaxSuminBST(TreeNode* root) {
    int sum=0;
    find(root,sum);
    return sum;
}
TreeNode* BST() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<root->data<<": ";
    root->left=BST();
    cout<<"Entre The Right Child of "<<root->data<<": ";
    root->right=BST();
    return root;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    cout<<MaxSuminBST(root);
}
