//Merge K Sorted linked list
#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* bottom;
    Node(int data)
    {
        this->data=data;
        this->bottom=NULL;
    }
};
Node* insertion(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->bottom=insertion(arr,i+1);
    return temp;
}
Node* mergeksortedlist(Node* root1,Node* root2)
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
int main()
{
    int n;
    cout<<"Entre The Root Size: ";
    cin>>n;
    vector<Node*>arr(n);
    for(int i=0;i<n;i++){
        int m;
        cout<<"Entre The Size: ";
        cin>>m;
        vector<int>a(m);
        cout<<"Entre The Element: ";
        for(int i=0;i<m;i++)
        cin>>a[i];
        arr[i]=insertion(a,0);
    }
    Node* root=arr[0];
    for(int i=1;i<arr.size();i++)
    root=mergeksortedlist(root,arr[i]);
    for(Node* i=root;i!=NULL;i=i->bottom){
        cout<<i->data<<" ";
    }
}