//
// Created by jishu on 23-07-2025.
//construct tree from array
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
TreeNode* createBT(vector<int>&arr,int i) {
    if (i>=arr.size())
        return NULL;
    if (arr[i]==-1)
        return NULL;
    TreeNode* root=new TreeNode(arr[i]);
    root->left=createBT(arr,2*i+1);
    root->right=createBT(arr,2*i+2);
    return root;
}
int main() {
    int n;
    cout<<"Size Of The Tree: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<arr.size();i++)
        cin>>arr[i];
    TreeNode* root=createBT(arr,0);
    preorder(root);
}
