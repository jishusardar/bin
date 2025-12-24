#include<iostream>
using namespace std;
class Stack
{
    int top;
    int size;
    int* arr;
    public:
    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int num)
    {
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=num;
    }
    int pop()
    {
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int temp=top;
        top--;
        return arr[temp];
    }
    int Top()
    {
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if(top==-1)
        return 1;
        return 0;
    }
    bool isFull()
    {
        if(top==size)
        return 1;
        return 0;
    }
};
int main()
{
    int m;
    cout<<"Entre The Size of Stack: ";
    cin>>m;
    Stack* s=new Stack(m);
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