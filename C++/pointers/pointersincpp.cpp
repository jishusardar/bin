#include<iostream>
using namespace std;
void printall(int arr[],int n)
{
    int *ptr=&arr[0];
    for(int i=0;i<n;i++){
        cout<<*(ptr+i)<<" ";
    }
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    printall(arr,n);
}