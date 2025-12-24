//stack implementation using dequeue
#include<iostream>
#include<deque>
using namespace std;
class Stack
{
    deque<int>dq;
    public:
    Stack()
    {

    }
    void push(int data)
    {
        dq.push_back(data);
    }
    int pop()
    {
        if(dq.size()==0){
            cout<<"Stack Underflow";
            return -1;
        }
        int num=dq.back();
        dq.pop_back();
        return num;
    }
    int top()
    {
        if(dq.size()==0)
        {
            cout<<"Stack Underflow";
            return -1;
        }
        return dq.back();
    }
};
int main()
{
    Stack *s=new Stack();
    int n=0;
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
        cout<<num<<endl;
        break;
        case 3:
        cout<<s->top()<<endl;
        break;
    }
    }
}