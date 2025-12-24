// clone a linked list
#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};
Node* clonelinked(Node* root)
{
    Node* curr=root;
    while(curr){
        Node* fut=curr->next;
        curr->next=new Node(curr->data);
        curr=curr->next;
        curr->next=fut;
        curr=fut;
    }
    curr=root;
    while(curr){
        Node* copyhead=curr->next;
        if(curr->random)
        copyhead->random=curr->random->next;
        curr=copyhead->next;
    }
    Node* ans=new Node(0);
    Node* temp=ans;
    curr=root;
    while(curr){
        Node* front=curr->next;
        temp->next=front;
        temp=temp->next;
        curr->next=front->next;
        curr=curr->next;
    }
    return ans->next;
}
Node* insertion(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=insertion(arr,i+1);
    return temp;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    Node* root=insertion(arr,0);
    root=clonelinked(root);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}