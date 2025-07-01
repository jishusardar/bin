//length of loop
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
Node* Createloop(Node* root)
{
    Node* temp=root;
    while(temp->next)
    temp=temp->next;
    Node* tempn=root;
    while(tempn->data!=4){
        tempn=tempn->next;
    }
    temp->next=tempn;
    return root;
}
int lengthofloop(Node* root)
{
    Node* fast=root;
    Node* slow=root;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    if(!fast&&!fast->next)
    return 0;
    slow=slow->next;
    int count=1;
    while(slow!=fast){
        count++;
        slow=slow->next;
    }    
    return count;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* root=insertion(arr,0);
    root=Createloop(root);
    cout<<"The Length of loop: "<<lengthofloop(root);
}