//dequeue imlmentation using linked list
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
       this->data=data;
       this->next=NULL;
       this->prev=NULL;
    }
};
class dequeue
{
    int data;
    Node* front;
    Node* rear;
    public:
    dequeue()
    {
        front=NULL;
        rear=NULL;
    }
    void pushfront(int data)
    {
        if(front==NULL){
            front=new Node(data);
            rear=front;
            return;
        }
        Node* temp=new Node(data);
        front->prev=temp;
        temp->next=front;
        front=temp;
    }
    void pushback(int data)
    {
        if(rear==NULL){
            rear=new Node(data);
            front=rear;
            return;
        }
        Node* temp=new Node(data);
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    int pop_front()
    {
        if(front==NULL){
            cout<<"Queue Underflow";
            return -1;
        }
        else if(front==rear){
            int num=front->data;
            front=rear=NULL;
            return num;
        }
        int num=front->data;
        front=front->next;
        front->prev=NULL; 
        return num;
    }
    int pop_back()
    {
        if(rear==NULL){
            cout<<"Queue Underflow";
            return -1;
        }
        else if(rear==front){
            int num=rear->data;
            rear=front=NULL;
            return num;
        }
        int num=rear->data;
        rear=rear->prev;
        rear->next=NULL;
        return num;
    }
    int start()
    {
        if(front==NULL)
        return -1;
        return front->data;
    }
    int end()
    {
        if(rear==NULL)
        return -1;
        return rear->data;
    }
};
int main()
{
    int n=0;
    dequeue*q=new dequeue();
    while(n!=-1){
        int p;
        cout<<"Entre 1 for push front: \n";
        cout<<"Entre 2 for push back: \n";
        cout<<"Entre 3 for pop front: \n";
        cout<<"Entre 4 for pop back: \n";
        cout<<"Entre 5 for front:\n";
        cout<<"Entre 6 for back: \n";
        cout<<"Entre 7 for Exit:\n";
        cout<<"Entre Desired Input: ";
        cin>>p;
        switch (p)
        {
            case 1:
            int data;
            cout<<"Entre The Data: ";
            cin>>data;
            q->pushfront(data);
            break;
            case 2:
            cout<<"Entre The Data: ";
            cin>>data;
            q->pushback(data);
            break;
            case 3:
            cout<<q->pop_front()<<endl;
            break;
            case 4:
            cout<<q->pop_back()<<endl;
            break;
            case 5:
            cout<<q->start()<<endl;
            break;
            case 6:
            cout<<q->end()<<endl;
            break;
            default:
            break;
        }
    }
}