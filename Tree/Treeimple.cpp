#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
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
    cout<<"Entre The Left Child of "<<root->data<<" :";
    root->left=Tree();
    cout<<"Entre The Right Child of "<<root->data<<" :";
    root->right=Tree();
    return root;
}
void Treaverse(Node* root) {
    if (!root)
        return;
    cout<<root->data;
    Treaverse(root->left);
    Treaverse(root->right);
}
int main() {
    cout<<"Entre The Root Element: ";
    Node* root=Tree();
    Treaverse(root);
}
