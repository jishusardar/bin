// largest value in each level
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
vector<int> largestineach(TreeNode* root) {
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        int n=q.size();
        int maxi=INT_MIN;
        while (n--) {
            TreeNode* temp=q.front();
            q.pop();
            maxi=max(maxi,temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(maxi);
    }
    return ans;
}
int main() {
    cout<<"Entre The Root Element: ";
    TreeNode* root=BST();
    vector<int>ans=largestineach(root);
    cout<<"The Largest in each Level: "<<endl;
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}
