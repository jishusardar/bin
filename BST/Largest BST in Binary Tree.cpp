//
// Created by jishu on 03-08-2025.
//Largest BST in Binary Tree
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
    int size;
    int min;
    int max;
    Box(int data) {
        BST=1;
        size=1;
        min=data;
        max=data;
    }
};
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
Box* find(TreeNode* root,int &totalsize) {
    if (!root->left&&!root->right){
        Box* head=new Box(root->data);
        totalsize=max(totalsize,head->size);
        return head;
    }
    else if (root->left&&!root->right) {
        Box* lefthead=find(root->left,totalsize);
        if (lefthead->BST&&lefthead->max<root->data) {
            Box* head=new Box(root->data);
            head->size+=lefthead->size;
            totalsize=max(totalsize,head->size);
            head->min=lefthead->min;
            return head;
        }
        else {
            lefthead->BST=0;
            return lefthead;
        }
    }
    else if (root->right&&!root->left) {
        Box* righthead=find(root->right,totalsize);
        if (righthead->BST&&righthead->min>root->data) {
            Box* head=new Box(root->data);
            head->size+=righthead->size;
            totalsize=max(totalsize,head->size);
            head->max=righthead->max;
            return head;
        }
        else {
            righthead->BST=0;
            return righthead;
        }
    }
    else {
        Box* lefthead=find(root->left,totalsize);
        Box* righthead=find(root->right,totalsize);
        if (lefthead->BST&&righthead->BST&&lefthead->max<root->data&&righthead->min>root->data) {
            Box* head=new Box(root->data);
            head->size+=lefthead->size+righthead->size;
            totalsize=max(totalsize,head->size);
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
int largetsBST(TreeNode* root) {
    int totalsize=0;
    find(root,totalsize);
    return totalsize;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    cout<<largetsBST(root);
}
