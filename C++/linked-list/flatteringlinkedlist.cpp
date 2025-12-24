//flattering linked list
#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* bottom;
    Node(int data)
    {
        this->data=data;
        this->bottom=NULL;
        this->next=NULL;
    }
};
Node* Insurtion(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=Insurtion(arr,i+1);
    return temp;
}
Node* bottominsurtion(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->bottom=bottominsurtion(arr,i+1);
    return temp;
}
void transform(Node* root)
{
    for(Node* i=root;i!=NULL;i=i->next){
        int n;
        cout<<"Entre The Size: ";
        cin>>n;
        vector<int>arr(n);
        cout<<"Entre The Element: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        i->bottom=bottominsurtion(arr,0);
    }
}
void printsalll(Node* root)
{
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
        for(Node* j=i->bottom;j!=NULL;j=j->bottom){
            cout<<j->data<<" ";
        }
        cout<<endl;
    }
}
Node* mergelist(Node* root1,Node* root2)
{
    Node* ans=new Node(0);
    Node* temp=ans;
    while(root1&&root2){
        if(root1->data<root2->data){
            temp->bottom=root1;
            root1=root1->bottom;
            temp=temp->bottom;
        }
        else{
            temp->bottom=root2;
            root2=root2->bottom;
            temp=temp->bottom;
        }
    }
    while(root1){
        temp->bottom=root1;
        root1=root1->bottom;
        temp=temp->bottom;
    }
    while(root2){
        temp->bottom=root2;
        root2=root2->bottom;
        temp=temp->bottom;
    }
    temp->bottom=NULL;
    return ans->bottom;
}
Node* flattering_linked_list(Node* root)
{
    Node* temp=root;
    Node* curr=NULL;
    while(temp->next){
        Node* fut=temp->next;
        if(fut->next)
        curr=fut->next;
        else
        curr=NULL;
        temp=mergelist(temp,fut);
        temp->next=curr;
    }
    return temp;
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
    Node* root=Insurtion(arr,0);
    transform(root);
    root=flattering_linked_list(root);
    for(Node* i=root;i!=NULL;i=i->bottom){
        cout<<i->data<<" ";
    }
}