//detect loop in a linked list
#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
Node* insertion(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=insertion(arr,i+1);
    return temp;
}
bool detectloop(Node* root)
{
    Node* slow=root;
    Node* fast=root;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    if(slow==fast)
    return 1;
    return 0;
}
Node* Createloop(Node* root)
{
    Node* temp=root;
    while(temp->next)
    temp=temp->next;
    Node* tempn=root;
    while(tempn->data!=4){
        tempn=tempn->next;
    }
    temp->next=tempn;
    return root;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    Node* root=insertion(arr,0);
    root=Createloop(root);
    if(detectloop(root))
    cout<<"The Loop is Present";
    else
    cout<<"The Loop is not Present";
}