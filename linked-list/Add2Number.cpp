//Add 2 Numbers
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
Node* insertions(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=insertions(arr,i+1);
    return temp;
}
Node* reverse(Node* curr,Node* prev)
{
    if(!curr)
    return prev;
    Node* fut=curr->next;
    curr->next=prev;
    return reverse(fut,curr);
}
Node* addNumbers(Node* root1,Node* root2)
{
    root1=reverse(root1,NULL);
    root2=reverse(root2,NULL);
    Node* temp1=root1;
    Node* temp2=root2;
    Node* ans=new Node(0);
    Node* temp=ans;
    int carry=0;
    while(temp1&&temp2){
        int sum=temp1->data+temp2->data+carry;
        carry=sum/10;
        sum%=10;
        temp->next=new Node(sum);
        temp1=temp1->next;
        temp2=temp2->next;
        temp=temp->next;
    }
    while(temp1){
        int sum=temp1->data+carry;
        carry=sum/10;
        sum%=10;
        temp->next=new Node(sum);
        temp1=temp1->next;
        temp=temp->next;
    }
    while(temp2){
        int sum=temp2->data+carry;
        carry=sum/10;
        sum%=10;
        temp->next=new Node(sum);
        temp2=temp2->next;
        temp=temp->next;
    }
    while(carry){
        int sum=carry;
        carry=sum/10;
        sum%=10;
        temp->next=new Node(sum);
        temp=temp->next;
    }
    ans=reverse(ans->next,NULL);
    return ans;
}
int main()
{
    int n,m;
    cout<<"Entre the Size: ";
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    cout<<"Entre The Element for list 1: ";
    for(int i=0;i<n;i++)
    cin>>arr1[i];
    cout<<endl;
    cout<<"Entre The Element for list 2: ";
    for(int i=0;i<m;i++)
    cin>>arr2[i];
    Node* root1=insertions(arr1,0);
    Node* root2=insertions(arr2,0);
    Node* root=addNumbers(root1,root2);
    for(Node* i=root;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}