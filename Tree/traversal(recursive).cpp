#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* Tree() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    Node* root=new Node(x);
    cout<<"Entre The Left Child of "<<root->data<<": ";
    root->left=Tree();
    cout<<"Entre The Right Child of "<<root->data<<": ";
    root->right=Tree();
    return root;
}
void preorder(Node* root) {
    if (!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main() {
    cout<<"Entre The Root Element: ";
    Node* root=Tree();
    cout<<"preorder Traversal of Tree: ";
    preorder(root);
    cout<<endl;
    cout<<"inorder traversal of Tree: ";
    inorder(root);
    cout<<endl;
    cout<<"postOrder Traversal of Tree: ";
    postorder(root);
    cout<<endl;
}
