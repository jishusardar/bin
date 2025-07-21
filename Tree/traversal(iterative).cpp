//preorder
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class TreeNode
{
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
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
    cout<<"Entre The left child for "<<x<<" : ";
    root->left=BST();
    cout<<"Entre The Right Child for "<<x<<" : ";
    root->right=BST();
    return root;
}
vector<int> preorder(TreeNode* root) {
    vector<int>ans;
    stack<TreeNode*>st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* temp=st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    return ans;
}
vector<int> levelordertraversal(TreeNode* root) {
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}
vector<int> PostTraversal(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* temp=st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
    return ans;
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;

}
int main() {
    cout<<"Entre The root element: ";
    TreeNode* root=BST();
    vector<int>ans2=PostTraversal(root);
    cout<<"The Post Traversal of the tree is "<<endl;
    reverse(ans2.begin(),ans2.end());
    for (int i=0;i<ans2.size();i++)
        cout<<ans2[i]<<" ";
    cout<<endl;
    vector<int>ans1=levelordertraversal(root);
    cout<<"The Level Order Traversal of the tree is: "<<endl;
    for (int i=0;i<ans1.size();i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    vector<int>ans=preorder(root);
    cout<<"The Preorder iterative Traversal of The Tree is: "<<endl;
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
