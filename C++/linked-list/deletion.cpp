// //deletion of last node
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
// Node* deletion(int pos,Node* root)
// {
//     if(pos==1){
//         root=root->next;
//         return root;
//     }
//     Node* prev=NULL;
//     Node* temp=root;
//     pos--;
//     while(pos--){
//         prev=temp;
//         temp=temp->next;
//     }
//     prev->next=temp->next;
//     delete temp;
//     return root;
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
//     cout<<endl;
//     int pos;
//     cout<<"Entre The pos To Delete: ";
//     cin>>pos;
//     root=deletion(pos,root);
//     for(Node* i=root;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }

// }
//delete a node using recursion
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
Node* deletion(int pos,Node* root)
{
    if(pos==1){
        Node* temp=root->next;
        delete root;
        return temp;
    }
    root->next=deletion(pos-1,root->next);
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
    Node* root=insertion(arr,0);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    int pos;
    cout<<"Entre The pos: ";
    cin>>pos;
    root=deletion(pos,root);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}