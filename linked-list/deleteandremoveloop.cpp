//delete and remove loop in a linked list
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
Node * insertion(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=insertion(arr,i+1);
    return temp;
}
Node* removeloop(Node* root)
{
    Node* slow=root;
    Node* fast=root;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    if(!root||!root->next)
    return root;
    int count=1;
    while(slow->next!=fast){
        count++;
        slow=slow->next;
    }
    slow=fast=root;
    while(count--){
        fast=fast->next;
    }
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    while(slow->next!=fast)
    slow=slow->next;
    slow->next=NULL;
    return root;
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
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node*root=insertion(arr,0);
    root=Createloop(root);
    if(detectloop(root))
    cout<<"loop is present"<<endl;
    else
    cout<<"Loops is not present"<<endl;
    root=removeloop(root);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}