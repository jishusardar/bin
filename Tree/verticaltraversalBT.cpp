//
// Created by jishu on 23-07-2025.
//vertical Traversla of Binary Tree
#include <iostream>
#include <queue>
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
void find(TreeNode* root,int &l,int &r,int pos) {
    if (!root)
        return;
    l=min(l,pos);
    r=max(r,pos);
    find(root->left,l,r,pos-1);
    find(root->right,l,r,pos+1);
}
vector<vector<int>> Traverse(TreeNode* root,vector<vector<int>>&neg,vector<vector<int>>&pos) {
    queue<TreeNode*>q;
    vector<vector<int>>ans;
    queue<int>index;
    q.push(root);
    index.push(0);
    while (!q.empty()) {
        TreeNode* temp=q.front();
        q.pop();
        int num=index.front();
        index.pop();
        if (num>=0) {
            pos[num].push_back(temp->data);
        }
        else {
            neg[abs(num)].push_back(temp->data);

        }
        if (temp->left) {
            q.push(temp->left);
            index.push(num-1);
        }
        if (temp->right) {
            q.push(temp->right);
            index.push(num+1);
        }
    }
    for (int i=neg.size()-1;i>0;i--) {
        ans.push_back(neg[i]);
    }
    for (int i=0;i<pos.size();i++) {
        ans.push_back(pos[i]);
    }
    return ans;
}
vector<vector<int>> verticalTraversalBT(TreeNode* root) {
    int l=0,r=0;
    find(root,l,r,0);
   vector<vector<int>>neg((-1*l)+1);
    vector<vector<int>>pos(r+1);
    return Traverse(root,neg,pos);
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Tree: ";
    for (int i=0;i<arr.size();i++)
        cin>>arr[i];
    TreeNode* root=createBT(arr,0);
    vector<vector<int>>ans=verticalTraversalBT(root);
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
