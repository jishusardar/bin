//total time to buy ticket
#include<iostream>
#include<queue>
using namespace std;
int totaltimebuyticket(int arr[],int n,int k)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    q.push(arr[i]);
    int time=0;
    while(arr[k]!=0){
        time++;
        arr[q.front()]--;
        if(arr[q.front()])
        q.push(q.front());
        q.pop();
    }
    return time;
}
int main()
{
    int n,k;
    cout<<"Entre The size: ";
    cin>>n;
    cout<<"Entre The K: ";
    cin>>k;
    int arr[n];
    cout<<"Entre The Element: "; 
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Total Time To Buy Ticket: "<<totaltimebuyticket(arr,n,k);
}