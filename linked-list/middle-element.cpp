//middle element of a linked list
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
Node* middleelemnt(Node* root)
{
    int count=0;
    for(Node* i=root;i!=NULL;i=i->next){
        count++;
    }
    if(count%2)
    count++;
    count/=2;
    Node* temp=root;
    while(--count){
        temp=temp->next;
    }
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
    root=middleelemnt(root);
    cout<<"The Middle Element is: "<<root->data<<" ";
}