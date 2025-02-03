//reverse linked list iterative approach
#include<bits/stdc++.h>
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
Node* createlinked(vector<int>arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=createlinked(arr,i+1);
    return temp;
}
//reverse in iterative approach
Node* reverselinked(Node* head)
{
    Node* curr=head;
    Node* pre=NULL;
    while(curr){
        Node* fut=curr->next;
        curr->next=pre;
        pre=curr;
        curr=fut;
    }
    return pre;
}
//reverse in recursive approach
Node* reverselinked(Node* curr,Node* pre)
{
    if(curr==NULL)
    return pre;
    Node* fut=curr->next;
    curr->next=pre;
    return reverselinked(fut,curr);
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Elemnt: ";
        cin>>arr[i];
    }
    Node* head=createlinked(arr,0);
    head=reverselinked(head);
    for(Node* i=head;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}