//get minimum in pop
#include<iostream>
#include<vector>
using namespace std;
class Stack
{
    int n;
    int *arr;
    int top;
    public:
    Stack(int n)
    {
        this->n=n;
        arr=new int[n];
        top=0;
    }
    void Push(int data)
    {
        if(top==n){
            cout<<"The Stack OverFlow";
            return;
        }
        else if(top==0){
            arr[top]=data;
            top++;
        }
        else
        {
            arr[top]=min(data,arr[top-1]);
            top++;
        }
    }
    int pop()
    {
        if(top==-1){
            cout<<"The Stak undeflow";
            return 0;
        }
        int num=arr[top];
        top--;
        return num;
    }
    int size()
    {
        return top+1;
    }
};
int main()
{
    Stack *s=new Stack(6);
    for(int i=1;i<=6;i++){
        s->Push(i);
    }
    while(s->size()){
        cout<<s->pop()<<" ";
    }
}