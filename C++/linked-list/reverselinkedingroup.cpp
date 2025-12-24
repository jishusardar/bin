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
Node* Insertions(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=Insertions(arr,i+1);
    return temp;
}
Node* ReverseIngroup(Node* head,int k)
{
    Node* first=new Node(0);
    first->next=head;
    Node* ans=first;
    while(first->next){
        Node* second=first->next;
        Node* curr=second;
        Node* prev=first;
        int x=k;
        while(x--&&curr){
            Node* fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        first->next=prev;
        second->next=curr;
        first=second;
    }
    return ans->next;
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
    Node* root=Insertions(arr,0);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
    int k;
    cout<<"Entre The group Sequence: ";
    cin>>k;
    root=ReverseIngroup(root,k);
    cout<<endl;
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}