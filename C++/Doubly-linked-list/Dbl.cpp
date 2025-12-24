//Doubly linked list
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
Node* Insertions(vector<int>&arr,int i,Node* pre)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->prev=pre;
    temp->next=Insertions(arr,i+1,temp);
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
    Node* root=Insertions(arr,0,NULL);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl<<"Now reverse"<<endl;
    while(root->next){
        root=root->next;
    }
    for(Node* i=root;i!=NULL;i=i->prev){
        cout<<i->data<<" ";
    }
}