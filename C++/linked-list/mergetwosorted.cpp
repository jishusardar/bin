//merge two sorted list
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
Node* Mergelists(Node* head1,Node* head2)
{
    Node* head=new Node(0);
    Node* temp=head;
    while(head1&&head2){
        if(head1->data<head2->data){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        else{
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
    }
    while(head1){
        temp->next=head1;
        head1=head1->next;
        temp=temp->next;
    }
    while(head2){
        temp->next=head2;
        head2=head2->next;
        temp=temp->next;
    }
    temp->next=NULL;
    head=head->next;
    return head;
}
int main()
{
    int n,m;
    cout<<"Entre The Size 1: ";
    cin>>n;
    vector<int>arr1(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element list 1: ";
        cin>>arr1[i];
    }
    Node* root1=insertion(arr1,0);
    cout<<"Entre The Size 2: ";
    cin>>m;
    vector<int>arr2(m);
    for(int i=0;i<m;i++){
        cout<<"Entre The Element list 2: ";
        cin>>arr2[i];
    }
    Node* root2=insertion(arr2,0);
    cout<<"The Linked list 1: "<<endl;
    for(Node* i=root1;i!=NULL;i=i->next)
    cout<<i->data<<" ";
    cout<<endl;
    cout<<"The Linked List 2: "<<endl;
    for(Node* i=root2;i!=NULL;i=i->next)
    cout<<i->data<<" ";
    cout<<endl;
    Node* root=Mergelists(root1,root2);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}