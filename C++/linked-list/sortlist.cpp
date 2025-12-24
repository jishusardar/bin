//sort a list contains 0 1 and 2
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
Node* sortlist(Node* root)
{
    Node* list0=new Node(0);
    Node* head0=list0;
    Node* list1=new Node(0);
    Node* head1=list1;
    Node* list2=new Node(0);
    Node* head2=list2;
    for(Node* i=root;i!=NULL;i=i->next){
        if(i->data==0){
            list0->next=i;
            list0=list0->next;
        }
        else if(i->data==1){
            list1->next=i;
            list1=list1->next;
        }
        else{
            list2->next=i;
            list2=list2->next;
        }
    }
    list0->next=NULL;
    list1->next=NULL;
    list2->next=NULL;
    head0=head0->next;
    head1=head1->next;
    head2=head2->next;
    Node* head=new Node(0);
    Node* temp=head;
    while(head0){
        temp->next=head0;
        temp=temp->next;
        head0=head0->next;
    }
    while(head1){
        temp->next=head1;
        temp=temp->next;
        head1=head1->next;
    }
    while(head2){
        temp->next=head2;
        temp=temp->next;
        head2=head2->next;
    }
    return head->next;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* root=insertion(arr,0);
    root=sortlist(root);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}