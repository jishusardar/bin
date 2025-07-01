//insertion in singly linked list
// #include<iostream>
// #include<vector>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* Next;
//     Node(int data)
//     {
//         this->data=data;
//         this->Next=NULL;
//     }
// };
// Node* insertionatend(vector<int>&arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->Next=insertionatend(arr,i+1);
//     return temp;
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
//     //Linked list
//     Node* root=insertionatend(arr,0);
//     for(Node* i=root;i!=NULL;i=i->Next){
//         cout<<i->data<<" ";
//     }
// }
//insertion at begin
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
// Node* insertionatbegin(vector<int>&arr,int i,Node* pre)
// {
//     if(i==arr.size()){
//         return pre;
//     }
//     Node* temp=new Node(arr[i]);
//     temp->next=pre;
//     return insertionatbegin(arr,i+1,temp);
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
//     Node* root=insertionatbegin(arr,0,NULL);
//     for(Node* i=root;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//insert at particular position
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
Node* insertatpos(int pos,int val,Node* root)
{
    if(pos==1){
        Node* tempn=new Node(val);
        tempn->next=root;
        return tempn;
    }
    Node* temp=root;
    pos--;
    while(--pos){
        temp=temp->next;
    }
    Node* tempn=new Node(val);
    tempn->next=temp->next;
    temp->next=tempn;
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
    int pos,val;
    cout<<"Entre The Pos: ";
    cin>>pos;
    cout<<"Entre The Val: ";
    cin>>val;
    root=insertatpos(pos,val,root);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}