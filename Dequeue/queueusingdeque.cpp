//queue using dequeue
#include<iostream>
#include<deque>
using namespace std;
class Queue
{
    deque<int>dq;
    public:
    Queue()
    {

    }
    void push(int data)
    {
        dq.push_back(data);
    }
    int pop()
    {
        if(dq.size()==0){
            cout<<"Queue Unerflow";
            return -1;
        }
        int num=dq.front();
        dq.pop_front();
        return num;
    }
    int front()
    {
        if(dq.size()==0){
            cout<<"Queue Underflow";
            return -1;
        }
        return dq.front();
    }
    int back()
    {
        if(dq.size()==0){
            cout<<"Queue Underflow";
            return -1;
        }
        return dq.back();
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
            cout<<q->front()<<endl;
            break;
            case 4:
            cout<<q->back()<<endl;
            break;
            default:
            break;
        }
    } 
}