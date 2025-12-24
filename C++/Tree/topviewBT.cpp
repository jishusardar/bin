//
// Created by jishu on 23-07-2025.
// TOP View Of Binary Tree
#include <algorithm>
#include <iostream>
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
//lets find the actual rightmost and left most nodes
void find_height(TreeNode* root,int &l,int &r,int pos) {
    if (!root)
        return;
    l=min(l,pos);
    r=max(r,pos);
    find_height(root->left,l,r,pos-1);
    find_height(root->right,l,r,pos+1);
}
//traverse through the tree and count the levels so that only min level element can be added into the solution
void traverse(TreeNode* root,int level,vector<int>&ans,vector<int>&count,int pos) {
    if (!root)
        return;
    if (count[pos]>level) {
        count[pos]=level;
        ans[pos]=root->data;
    }
    traverse(root->left,level+1,ans,count,pos-1);
    traverse(root->right,level+1,ans,count,pos+1);
}
vector<int> TopviewofBT(TreeNode* root) {
    int l=0,r=0;
    find_height(root,l,r,0);
    vector<int>ans(r-l+1);
    // count is used bcoz we are traversing the left side first so the lower of nodes with same index can be get into array
    //edge cases https://chatgpt.com/c/68801d66-e0d4-800a-9555-bc6727d27825
    vector<int>count(r-l+1,INT_MAX);
    traverse(root,0,ans,count,-1*l);
    return ans;
}
TreeNode* BT() {
    int x;
    cin>>x;
    if (x==-1)
        return NULL;
    TreeNode* root=new TreeNode(x);
    cout<<"Entre The Left Child of "<<x<<" : ";
    root->left=BT();
    cout<<"Entre The Right Child of "<<x<<" : ";
    root->right=BT();
    return root;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    vector<int>ans=TopviewofBT(root);
    cout<<"The Top View of BT is : ";
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
