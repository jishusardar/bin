//
// Created by jishu on 04-08-2025.
//deletion in avl tree
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    int height;
    Node* left;
    Node*right;
    Node(int val) {
        data=val;
        height=1;
        left=right=NULL;
    }
};
int getHeight(Node* root) {
    if (!root)
        return 0;
    return root->height;
}
int getBalance(Node* root) {
    return getHeight(root->left)-getHeight(root->right);
}
Node* rightrotate(Node* root) {
    Node* child=root->left;
    Node* childright=child->right;
    child->right=root;
    root->left=childright;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(root->left),getHeight(root->right));
    return child;
}
Node* leftrotate(Node* root) {
    Node* child=root->right;
    Node* childleft=child->left;
    child->left=root;
    root->right=childleft;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(root->left),getHeight(root->right));
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
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int balance=getBalance(root);
    //left left
    if (balance>1&&val<root->left->data)
        return rightrotate(root);
    if (balance<-1&&val>root->right->data)
        return leftrotate(root);
    if (balance>1&&val>root->left->data) {
        root->left=leftrotate(root->right);
        return rightrotate(root);
    }
    if (balance<-1&&val<root->right->data) {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    else
        return root;
}
void preorder(Node* root) {
    if (!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node* deleteion(Node* root,int val) {
    if (!root)
        return NULL;
    else if (root->data>val)
        root->left=deleteion(root->left,val);
    else if (root->data<val)
        root->right=deleteion(root->right,val);
    else {
        if (!root->left&&!root->right) {
            delete root;
            return NULL;
        }
        else if (!root->right&&root->left) {
            Node* curr=root->left;
            delete root;
            return curr;
        }
        else if (!root->left&&root->right) {
            Node* curr=root->right;
            delete root;
            return curr;
        }
        else {
            //right side ka minimum element
            Node* temp=root->right;
            while (temp->left) {
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteion(root->right,temp->data);
        }
    }
    int balance=getBalance(root);
    if (balance>1&&val<root->left->data)
        return rightrotate(root);
    if (balance<-1&&val>root->right->data)
        return leftrotate(root);
    if (balance>1&&val>root->left->data) {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance<-1&&val<root->right->data) {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    else
        return root;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    Node* root=NULL;
    for (int i=0;i<n;i++)
        root=insertion(root,arr[i]);
    preorder(root);
    int val;
    cout<<"Entre The Value to delete: ";
    cin>>val;
    root=deleteion(root,val);
    preorder(root);
}
