//insertion at Doubly linked list
#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
Node* insertions(vector<int>&arr,int i,Node* pre)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->prev=pre;
    temp->next=insertions(arr,i+1,temp);
    return temp;
}
Node* insertionatpos(Node* root,int pos,int val)
{
    if(pos==1){
        Node* temp=new Node(val);
        temp->next=root;
        root->prev=temp;
        return temp;
    }
    Node* temp=root;
    pos--;
    while(--pos){
        temp=temp->next;
    }
    Node* curr=temp->next;
    temp->next=new Node(val);
    temp->next->prev=temp;
    temp->next->next=curr;
    if(curr)
    curr->prev=temp->next;
    return root;
}
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    Node* root=insertions(arr,0,NULL);
    int pos;
    cout<<"Entre The pos: ";
    cin>>pos;
    int val;
    cout<<"Entre The Value: ";
    cin>>val;
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
    cout<<endl;
    root=insertionatpos(root,pos,val);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}
