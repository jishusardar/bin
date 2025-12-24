//level order traversal in spiral form
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
vector<int> levelorder(TreeNode* root) {
    vector<int>ans;
    stack<TreeNode*>s1; // right to left
    stack<TreeNode*>s2; //left to right
    s1.push(root);
    while (!(s1.empty()&&s2.empty())){
        if (s2.empty()) {
            while (!s1.empty()) {
                TreeNode* temp=s1.top();
                s1.pop();
                if (temp->right) {
                    s2.push(temp->right);
                }
                if (temp->left) {
                    s2.push(temp->left);
                }
                ans.push_back(temp->data);
            }
        }
        if (s1.empty()) {
            while (!s2.empty()) {
                TreeNode* temp=s2.top();
                s2.pop();
                if (temp->left) {
                    s1.push(temp->left);
                }
                if (temp->right) {
                    s1.push(temp->right);
                }
                ans.push_back(temp->data);
            }
        }
    }
    return ans;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    vector<int>ans=levelorder(root);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
