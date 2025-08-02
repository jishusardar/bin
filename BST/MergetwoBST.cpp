//
// Created by jishu on 01-08-2025.
//Merge Two BST
#include <iostream>
#include <vector>
#include <stack>
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
void Nextpush(TreeNode* root,stack<TreeNode*>&st) {
    while (root) {
        st.push(root);
        root=root->left;
    }
}
vector<int> MergeBST(TreeNode* root1,TreeNode* root2) {
    stack<TreeNode*>s1;
    stack<TreeNode*>s2;
    vector<int>ans;
    while (root1) {
        s1.push(root1);
        root1=root1->left;
    }
    while (root2) {
        s2.push(root2);
        root2=root2->left;
    }
    while (!s1.empty()&&!s2.empty()) {
        if (s1.top()->data>s2.top()->data) {
            ans.push_back(s2.top()->data);
            root2=s2.top()->right;
            s2.pop();
            Nextpush(root2,s2);
        }
        else {
            ans.push_back(s1.top()->data);
            root1=s1.top()->right;
            s1.pop();
            Nextpush(root1,s1);
        }
    }
    while (!s1.empty()) {
        ans.push_back(s1.top()->data);
        root1=s1.top()->right;
        s1.pop();
        Nextpush(root1,s1);
    }
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        root2=s2.top()->right;
        s2.pop();
        Nextpush(root2,s2);
    }
    return ans;
}
int main() {
    int n,m;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root=NULL;
    for (int i=0;i<n;i++)
        root=CBST(root,arr[i]);
    cout<<"Entre The Size for array 2: ";
    cin>>m;
    vector<int>arr2(m);
    cout<<"Entre The Element For Array 2: ";
    for (int i=0;i<m;i++)
        cin>>arr2[i];
    TreeNode* root1=NULL;
    for (int i=0;i<m;i++)
        root1=CBST(root1,arr2[i]);
    vector<int>ans=MergeBST(root,root1);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
