//print all the numbers in every window of size k
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void display(queue<int>q)
{
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void printallnumberswin(vector<int>&arr,int k)
{
    queue<int>q;
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }
    for(int i=k-1;i<arr.size();i++){
        q.push(arr[i]);
        display(q);
        q.pop();
    }
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int k;
    cout<<"Entre The Window Size: ";
    cin>>k;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    printallnumberswin(arr,k);
}