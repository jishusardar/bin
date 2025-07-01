//intersection in y shaped linked list
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
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head=insertion(arr,0);
    //https://github.com/jishusardar/GFG-PROBS/blob/main/Difficulty%3A%20Medium/Intersection%20in%20Y%20Shaped%20Lists/intersection-in-y-shaped-lists.cpp
}