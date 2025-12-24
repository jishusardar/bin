//
// Created by jishu on 24-07-2025.
//so for diagonal traversal we see a pattern that we will increase the level only
//when visiting the left side of the tree otherwise not
#include <iostream>
#include <queue>
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
TreeNode *createBT(vector<int> &arr, int i) {
    if (i >= arr.size())
        return NULL;
    if (arr[i] == -1)
        return NULL;
    TreeNode *root = new TreeNode(arr[i]);
    root->left = createBT(arr, 2 * i + 1);
    root->right = createBT(arr, 2 * i + 2);
    return root;
}
void find(TreeNode* root,int &l,int level) {
    if (!root)
        return;
    l=max(l,level);
    find(root->left,l,level+1);
    find(root->right,l,level);
}
vector<int> DiagonalTraversal(TreeNode* root) {
    int l=0;
    find(root,l,0);
    vector<vector<int>>ans(l+1);
    vector<int>arr;
    stack<TreeNode*>s1;
    stack<int>s2;
    s1.push(root);
    s2.push(0);
    while (!s1.empty()) {
        TreeNode* temp=s1.top();
        s1.pop();
        int pos=s2.top();
        s2.pop();
        ans[pos].push_back(temp->data);
        if (temp->right) {
            s1.push(temp->right);
            s2.push(pos);
        }
        if (temp->left) {
            s1.push(temp->left);
            s2.push(pos+1);
        }
    }
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<ans[i].size();j++)
            arr.push_back(ans[i][j]);
    }
    return arr;
}
int main() {
    vector<int>arr={8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    TreeNode* root=createBT(arr,0);
    vector<int>ans=DiagonalTraversal(root);
    cout<<"The Diagonal Traversal: ";
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
