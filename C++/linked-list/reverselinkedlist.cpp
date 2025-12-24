// //reverse linked list
// #include<iostream>
// #include<vector>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* insertion(vector<int>&arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=insertion(arr,i+1);
//     return temp;
// }
// Node* reverselinkedlist(Node* root,Node* prev)
// {
//     while(root){
//         Node* temp=root->next;
//         root->next=prev;
//         prev=root;
//         root=temp;
//     }
//     return prev;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     Node* root=insertion(arr,0);
//     for(Node* i=root;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
//     root=reverselinkedlist(root,NULL);
//     cout<<endl;
//     for(Node* i=root;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//reverse linked list using recursion
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
Node* reverse(Node* root,Node* prev)
{
    if(root==NULL){
        return prev;
    }
    Node* fut=root->next;
    root->next=prev;
    return reverse(fut,root);
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
    for(Node*i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    root=reverse(root,NULL);
    for(Node*i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}