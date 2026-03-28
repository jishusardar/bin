// implement queue using stack
#include<iostream>
#include<stack>
using namespace std;
class Queue
{
    stack<int>st1;
    stack<int>st2;
    public:
    Queue()
    {

    }
    void push(int data)
    {
       st1.push(data); 
    }
    int pop()
    {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int num=st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return num;
    }
    int start()
    {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int num=-1;
        if(!st2.empty())
        num=st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return num;
    }
    int end()
    {
        if(!st1.empty())
        return st1.top();
        return -1;
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