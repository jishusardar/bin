//
// Created by jishu on 30-07-2025.
//sum of k smallest element
//tested in gfg
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
TreeNode* CBST(TreeNode* root,int val) {
    if (!root) {
        root=new TreeNode(val);
        return root;
    }
    if (root->data>val)
        root->left=CBST(root->left,val);
    else
        root->right=CBST(root->right,val);
    return root;
}
void ksmallelement(TreeNode* root,int &sum,int &k) {
    if (!root)
        return;
    ksmallelement(root->left,sum,k);
    if (k) {
        sum+=root->data;
        k--;
    }
    ksmallelement(root->right,sum,k);
}
int sumel(TreeNode* root,int k) {
    int sum=0;
    ksmallelement(root,sum,k);
    return sum;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root=NULL;
    for (int i=0;i<n;i++)
        root=CBST(root,arr[i]);
    int k;
    cout<<"Entre The Kth Term: ";
    cin>>k;
    cout<<sumel(root,k);
}
