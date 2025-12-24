//remove duplicate element from a linked list
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
Node* RemoveDuplicate(Node* root)
{
    Node*temp=root;
    Node* head=root;
    Node* curr=head;
    temp=temp->next;
    while(temp){
        while(temp&&curr->data==temp->data)
        temp=temp->next;
        if(!temp)
        break;
        curr->next=temp;
        curr=curr->next;
        temp=temp->next;
    }
    curr->next=NULL;
    return head;
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
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
    cout<<endl;
    root=RemoveDuplicate(root);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}