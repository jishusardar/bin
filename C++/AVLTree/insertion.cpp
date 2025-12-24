//
// Created by jishu on 04-08-2025.
//insertion in avl tree
#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int val) {
        data=val;
        height=1;
        right=left=NULL;
    }
};
int getheight(Node* root) {
    if (!root)
        return 0;
    return root->height;
}
int getbalance(Node* root) {
 return getheight(root->left)-getheight(root->right);
}
Node* rightrot(Node* root) {
    Node* child=root->left;
    Node* childright=child->right;
    child->right=root;
    root->left=childright;
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}
Node* leftrot(Node* root) {
    Node* child=root->right;
    Node* childleft=child->left;
    child->left=root;
    root->right=childleft;
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(root->right));
    return child;
}
Node* insertion(Node* root,int val) {
    if (!root)
        return new Node(val);
    else if (root->data<val)
        root->right=insertion(root->right,val);
    else if (root->data>val)
        root->left=insertion(root->left,val);
    else
        return root;
    root->height=1+max(getheight(root->left),getheight(root->right));
    int balance=getbalance(root);
    //left left
    if (balance>1&&root->left->data>val)
        return rightrot(root);
    //right right
    if (balance<-1&&root->right->data<val)
        return leftrot(root);
    //left right
    if (balance>1&&root->left->data<val) {
        root->left=leftrot(root->left);
        return rightrot(root);
    }
    //right left
    if (balance<-1&&root->right->data>val) {
        root->right=rightrot(root->right);
        return leftrot(root);
    }
    return root;
}
void inordertraverse(Node* root) {
    if (!root)
        return;
    inordertraverse(root->left);
    cout<<root->data<<" ";
    inordertraverse(root->right);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    Node* root=NULL;
    for (int i=0;i<arr.size();i++)
        root=insertion(root,arr[i]);
    inordertraverse(root);
}
