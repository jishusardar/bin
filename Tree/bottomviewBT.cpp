//
// Created by jishu on 23-07-2025.
//
//bottom view of Binary Tree
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
void find(TreeNode* root,int &l,int &r,int pos) {
    if (!root)
        return;
    l=min(l,pos);
    r=max(r,pos);
    find(root->left,l,r,pos-1);
    find(root->right,l,r,pos+1);
}
void Traverse(TreeNode* root,vector<int>&ans,vector<int>&count,int pos,int level) {
    if (!root)
        return;
    if (count[pos]<=level) {
        count[pos]=level;
        ans[pos]=root->data;
    }
    Traverse(root->left,ans,count,pos-1,level+1);
    Traverse(root->right,ans,count,pos+1,level+1);
}
vector<int> BottomviewofBT(TreeNode* root) {
    int l=0,r=0;
    find(root,l,r,0);
    vector<int>ans((r-l)+1);
    vector<int>count((r-l)+1,INT_MIN);
    Traverse(root,ans,count,-1*l,0);
    return ans;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    vector<int>ans=BottomviewofBT(root);
    cout<<"The Bottom View of BST: ";
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
