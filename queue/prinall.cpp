//print all element
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void printall(int arr[],int n)
{
    queue<int>q;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
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
    printall(arr,n);
}