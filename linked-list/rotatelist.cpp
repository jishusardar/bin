//rotate list
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
Node* rotatelist(Node* root,int pos)
{
    int count=0;
    for(Node* i=root;i!=NULL;i=i->next){
        count++;
    }
    count-=pos;
    Node* temp=root;
    while(--count){
        temp=temp->next;
    }
    Node* curr=temp->next;
    temp->next=NULL;
    Node* head=curr;
    while(curr->next)
    curr=curr->next;
    curr->next=root;
    return head;
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
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    Node* root=insertion(arr,0);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    int pos;
    cout<<"Entre The pos To rotate: ";
    cin>>pos;
    cout<<endl;
    root=rotatelist(root,pos);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}