//recursion in array
#include<iostream>
using namespace std;
void prints(int i,int n,int arr[])
{
    if(i==n)
    return;
    cout<<arr[i]<<" ";
    prints(i+1,n,arr);
}
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>*(arr+i);
    }
    prints(0,n,arr);
}