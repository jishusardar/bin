//implement stack using queue
#include<iostream>
#include<queue>
using namespace std;
class Stack
{
    queue<int>q1;
    queue<int>q2;
    public:
    Stack()
    {
    }
    void push(int data)
    {
        q1.push(data);
    }
    int pop()
    {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int num=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
    int top()
    {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int num=q1.front();
        q2.push(q1.front());
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
};
int main()
{
    int n=0;
    Stack *s=new Stack();
    while(n!=-1){
        int p;
        cout<<"Entre 1 for push: \n";
        cout<<"Entre 2 for pop: \n";
        cout<<"Entre 3 for top:\n";
        cout<<"Entre Desired Input: ";
        cin>>p;
        switch (p)
        {
            case 1:
            int data;
            cout<<"Entre The Data: ";
            cin>>data;
            s->push(data);
            break;
            case 2:
            cout<<s->pop()<<endl;
            break;
            case 3:
            cout<<s->top()<<endl;
            break;
            default:
            break;
        }
    }
}