//check palindrome
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
    if(!root)
    return prev;
    Node* fut=root->next;
    root->next=prev;
    return reverse(fut,root);
}
bool checkpallindrome(Node* head)
{
    int count=0;
    for(Node* i=head;i!=NULL;i=i->next){
        count++;
    }
    count/=2;
    Node* head1=head;
    Node* root=head;
    while(--count){
        root=root->next;
    }
    Node* head2=root->next;
    root->next=NULL;
    head2=reverse(head2,NULL);
    while(head1&&head2){
        if(head1->data!=head2->data)
        return 0;
        head1=head1->next;
        head2=head2->next;
    }
    return 1;
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
    Node* root=insertion(arr,0);
    for(Node* i=root;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    if(checkpallindrome(root)){
        cout<<"The linked list is pallindrome"<<endl;
    }
    else
    cout<<"The Linked list is not pallindrome"<<endl;
}