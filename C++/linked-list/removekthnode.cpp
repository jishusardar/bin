//remmove every kth node
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
Node* insert(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=insert(arr,i+1);
    return temp;
}
Node* removeverykthnode(Node* root,int k)
{
    if(k==1)
    return NULL;
    Node* curr=root;
    Node* prev;
    int count=1;
    while(curr){
        if(count==k){
            Node* temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            delete temp;
            count=1;
        }
        else{
            prev=curr;
            curr=curr->next;
            count++;
        }
    }
    return root;
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
     int k;
    cout<<"Entre The sequence: ";
    cin>>k;
    Node* root=insert(arr,0);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    root=removeverykthnode(root,k);
    for(Node*i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}