//
// Created by jishu on 31-07-2025.
//a preorder traversal is given and check whether the  can construct tree
#include <chrono>
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
bool canRpresentinTree(vector<int>&pre) {
    //solve it by iteration method
    stack<int>lower;
    stack<int>upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    for (int i=0;i<pre.size();i++) {
        if (pre[i]<lower.top())
            return 0;
        while (pre[i]>upper.top()) {
            upper.pop();
            lower.pop();
        }
        int left=lower.top();
        int right=upper.top();
        lower.pop();
        upper.pop();
        //right side upper and lower of the root
        lower.push(pre[i]);
        upper.push(right);
        //left side upper and lower of the root
        lower.push(left);
        upper.push(pre[i]);
    }
    return 1;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    if (canRpresentinTree(arr))
        cout<<"The Preorder Traversal can be implemeneted into BST";
    else
        cout<<"The Preorder Traversal can not be implemented into BST";
}
