//implement two stacks
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Stack
{
    int *arr;
    int top1;
    int top2;
    int n;
    public:
    Stack(int n)
    {
        this->n=n;
        arr=new int[n];
        top1=-1;
        top2=n;
    }
    void push1(int data)
    {
        if(top1+1==top2){
            cout<<"Stack Overflow";
            return;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }
    void push2(int data)
    {
        if(top2-1==top1){
            cout<<"Stack Overflow";
            return;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }
    int pop1()
    {
        if(top1==-1){
            cout<<"Stack Undeflow";
            return -1;
        }
        else{
            int num=arr[top1];
            top1--;
            return num;
        }
    }
    int pop2()
    {
        if(top2==n){
            cout<<"Stack Underflow";
            return -1;
        }
        else{
            int num=arr[top2];
            top2++;
            return num;
        }
    }
};
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    Stack* s=new Stack(n);
    s->push1(12);
    s->push2(21);
    cout<<s->pop1()<<" "<<s->pop2();
    cout<<s->pop1()<<" "<<s->pop2();
}