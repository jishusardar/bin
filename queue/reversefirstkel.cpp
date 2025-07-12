//reverse first k element of queue
#include<iostream>
#include<stack>
using namespace std;
void reversekelement(int arr[],int n,int k)
{
    stack<int>st;
    for(int i=0;i<k;i++)
    st.push(arr[i]);
    int i=0;
    while(!st.empty()){
        arr[i]=st.top();
        i++;
        st.pop();
    }
}
int main()
{
    int n,k;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The k: ";
    cin>>k; 
    int arr[n];
    cout<<"Elment Element: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    reversekelement(arr,n,k);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}