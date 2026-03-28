//queue reversal
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void queuereversal(int arr[],int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    q.push(arr[i]);
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    queuereversal(arr,n);
}