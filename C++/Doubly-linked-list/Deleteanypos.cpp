//Delete any pos in linked list
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
        this->prev=NULL;
        this->next=NULL;
    }
};
Node* insertionll(vector<int>&arr,int i,Node* pre)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=insertionll(arr,i+1,temp);
    temp->prev=pre;
    return temp;
}
Node* Deleteatanypos(Node* head,int pos)
{
    if(pos==1){
        Node* temp=head;
        temp=temp->next;
        temp->prev=NULL;
        delete head;
        return temp;
    }
    Node* temp=head;
    pos--;
    while(pos--)
    temp=temp->next;
    Node* curr=temp;
    curr->prev->next=curr->next;
    if(curr->next)
    curr->next->prev=curr->prev;
    return head;
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
    Node* root=insertionll(arr,0,NULL);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    int pos;
    cout<<"Entre The Pos to Delete: ";
    cin>>pos;
    root=Deleteatanypos(root,pos);
    cout<<endl;
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}