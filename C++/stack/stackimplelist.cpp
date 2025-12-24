//implemenet stack using linked list
#include<iostream>
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
class Stack
{
    Node* top;
    public:
    Stack()
    {
        top=NULL;
    }
    void push(int num)
    {
        if(top==NULL){
            top=new Node(num);
            return;
        }
        Node* temp=new Node(num);
        temp->next=top;
        top=temp;
    }
    int pop()
    {
        if(top==NULL){
            cout<<"The Stack Underflow"<<endl;
            return -1;
        }
        int num=top->data;
        top=top->next;
        return num;
    }
    int Top()
    {
        if(!top){
            cout<<"Stack Undeflow"<<endl;
            return -1;
        }
        return top->data;
    }
};
int main()
{
    Stack* s=new Stack();
    int n;
    while(n!=4){
    cout<<"Entre 1 For Insertion: \n";
    cout<<"Entre 2 For Deletion: \n";
    cout<<"Entre 3 For Top: \n";
    cout<<"Entre 4 for Exit\n";
    cout<<"Entre The Choice: ";
    cin>>n;
    switch(n){
        case 1:
        int num;
        cout<<"Entre The number: ";
        cin>>num;
        s->push(num);
        break;
        case 2:
        num=s->pop();
        cout<<"The Deleted Element is: "<<num<<endl;
        break;
        case 3:
        cout<<s->Top()<<endl;
    }
    }
}