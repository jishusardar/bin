// remove nth node from end
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
Node* removenthnode(Node* root,int pos)
{
    int count=0;
    for(Node*i=root;i!=NULL;i=i->next){
        count++;
    }
    count-=pos;
    if(count==0){
        root=root->next;
        return root;
    }
    Node* temp=root;
    Node* prev;
    while(count--){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    return root;
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
    Node* root=insert(arr,0);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    int pos;
    cout<<"Entre The Pos From End: ";
    cin>>pos;
    root=removenthnode(root,pos);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}