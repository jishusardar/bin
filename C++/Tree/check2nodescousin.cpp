//check if two nodes are cousin
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
void checkcousin(TreeNode* root,int a,int b,bool& ans) {
    if (!root)
        return;
    if (root->left&&root->right) {
        if (root->left->data==a&& root->right->data==b)
            ans=1;
        if (root->left->data==b&&root->right->data==a)
            ans=1;
    }
    checkcousin(root->left,a,b,ans);
    checkcousin(root->right,a,b,ans);
}
TreeNode* BST() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=BST();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BST();
    return root;
}
int main(){
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    bool ans=0;
    int a,b;
    cout<<"Entre The Nodes of Cousins to check: ";
    cin>>a>>b;
    checkcousin(root,a,b,ans);
    if (ans)
        cout<<"The Nodes are cousins";
    else
        cout<<"The Nodes are Not Cousins";
}
