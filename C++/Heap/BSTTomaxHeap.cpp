//
// Created by jishu on 15-08-2025.
//BST to MaxHeap
#include <iostream>
#include <stack>
#include <vector>
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
TreeNode* CreateTree() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=CreateTree();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=CreateTree();
    return root;
}
vector<int> inorder(TreeNode* root) {
    vector<int>ans;
    stack<pair<TreeNode*,int>>st;
    st.push({root,0});
    while (!st.empty()) {
        pair<TreeNode*,int> s=st.top();
        st.pop();
        if (s.second==1) {
            ans.push_back(s.first->data);
        }
        else {
            if (s.first->right)
                st.push({s.first->right,0});
            st.push({s.first,1});
            if (s.first->left)
                st.push({s.first->left,0});
        }
    }
    return ans;
}
void postorder(TreeNode* root,vector<int>&inorder,int &index) {
    if (!root)
        return;
    postorder(root->left,inorder,index);
    postorder(root->right,inorder,index);
    root->data=inorder[index++];
}
void ConvertBTToMaxheap(TreeNode* root) {
    vector<int>ans=inorder(root);
    int index=0;
    postorder(root,ans,index);
}
void preorder(TreeNode* root) {
    if (!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=CreateTree();
    ConvertBTToMaxheap(root);
    preorder(root);
}
