//queue implementtation using array
#include<iostream>
#include<vector>
using namespace std;
class Queue
{
    int* arr;
    int front;
    int back;
    int n;
    public:
    Queue(int n)
    {
        this->n=n;
        arr=new int[n];
        front=0;
        back=0;
    }
    void push(int data)
    {
        if((back-n+1)%n==front){
            cout<<"Queue Overflow";
            return;
        }
        else{
            arr[back]=data;
            back=(back-n+1)%n;
        }
    }
    int pop()
    {
        if((front-n+1)%n>back){
            cout<<"Queue Underflow:";
            return -1;
        }
        else{
            int num=arr[front];
            front=(front-n+1)%n;
            return num;
        }
    }
    int start()
    {
       return arr[front];
    }
    int end()
    {
       return arr[back];
    }
};
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    Queue *q=new Queue(n);   
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