//
// Created by jishu on 24-07-2025.
//post order traversal using morris traversal
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
    cout<<"Entre The Left Child "<<x<<" : ";
    root->left=BT();
    cout<<"Entre The Right Child "<<x<<" : ";
    root->right=BT();
    return root;
}
vector<int> postorder(TreeNode* root) {
    vector<int>ans;
    while (root) {
        ans.push_back(root->data);
        if (root->right) {
            TreeNode* curr=root->right;
            while (curr->left) {
                curr=curr->left;
            }
            if (!curr->left) {
                if (root->left)
                    curr->left=root->left;
                root=root->right;
            }
            else
                root=root->left;
        }
        else
            root=root->left;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void postrec(TreeNode* root) {
    if (!root)
        return;
    postrec(root->left);
    postrec(root->right);
    cout<<root->data<<" ";
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BT();
    postrec(root);
    vector<int>ans=postorder(root);
    cout<<endl;
    cout<<"The Post Order Traversal: ";
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";


}
