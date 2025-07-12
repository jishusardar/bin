//queue implementation
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
class Queue
{
    Node* front;
    Node* back;
    public:
    Queue()
    {
        front=NULL;
        back=NULL;
    }
    void push(int data)
    {
        if(back==NULL){
            back=new Node(data);
            front=back;
        }
        else{
            back->next=new Node(data);
            back=back->next;
        }
    }
    int pop()
    {
        if(front==NULL){
            cout<<"Queue Underflow";
            return -1;
        }
        else{
            int num=front->data;
            front=front->next;
            return num;
        }
    }
    int start()
    {
        if(front==NULL){
            cout<<"Queue Underflow";
            return -1;
        }
        return front->data;
    }
    int end()
    {
        if(back==NULL){
            cout<<"Queue Underflow";
            return -1;
        }
        return back->data;
    }
};
int main()
{
    int n=0;
    Queue *q=new Queue();   
    while(n!=-1){
        int p;
        cout<<"Entre 1 for push: \n";
        cout<<"Entre 2 for pop: \n";
        cout<<"Entre 3 for front:\n";
        cout<<"Entre 4 for back: \n";
        cout<<"Entre 5 for Exit:\n";
        cout<<"Entre Desired Input: ";
        cin>>p;
        switch (p)
        {
            case 1:
            int data;
            cout<<"Entre The Data: ";
            cin>>data;
            q->push(data);
            break;
            case 2:
            cout<<q->pop()<<endl;
            break;
            case 3:
            cout<<q->start()<<endl;
            break;
            case 4:
            cout<<q->end()<<endl;
            break;
            default:
            break;
        }
    }
}