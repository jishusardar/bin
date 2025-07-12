//adobe hackathon
#include<bits/stdc++.h>
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
// 1containg element divisible by x
// 1 containign elementb not div by x
//reverse element k group 
//merge the list back by alternating element from each list while maintaing themodified order
Node* CreateLinkedlist(vector<int>&arr,int i)
{
    if(i==arr.size())
    return NULL;
    Node* temp=new Node(arr[i]);
    temp->next=CreateLinkedlist(arr,i+1);
    return temp;
}
Node* ReverseIngroup(Node* head,int k)
{
    Node* first=new Node(0);
    first->next=head;
    Node* ans=first;
    while(first->next){
        Node* second=first->next;
        Node* curr=second;
        Node* prev=first;
        int x=k;
        while(x--&&curr){
            Node* fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        first->next=prev;
        second->next=curr;
        first=second;
    }
    return ans->next;
}
Node* Mergelists(Node* head1,Node* head2)
{
    Node* head=new Node(0);
    Node* temp=head;
    bool count=0;
    while(head1&&head2){
        if(count==0){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
            count=1;
        }
        else{
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
            count=0;
        }
    }
    while(head1){
        temp->next=head1;
        head1=head1->next;
        temp=temp->next;
    }
    while(head2){
        temp->next=head2;
        head2=head2->next;
        temp=temp->next;
    }
    temp->next=NULL;
    head=head->next;
    return head;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int x;
    cin>>x;
    int k;
    cin>>k; 
    //element divisibkle by x
    vector<int>arr1;
    // elements not divisisbloe by x
    vector<int>arr2;
    for(int i=0;i<n;i++){
        if(arr[i]%x)
        arr2.push_back(arr[i]);
        else
        arr1.push_back(arr[i]);
    }
    Node* list1=CreateLinkedlist(arr1,0);
    Node* list2=CreateLinkedlist(arr2,0);
    list1=ReverseIngroup(list1,k);
    list2=ReverseIngroup(list2,k);
    Node* ans=Mergelists(list1,list2);
    for(Node* i=ans;i!=NULL;i=i->next)
    cout<<i->data<<" ";
}