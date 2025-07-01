//sum of all elements
#include<iostream>
using namespace std;
int sumofall(int arr[],int n)
{
    if(n==-1)
    return 0;
    return arr[n]+sumofall(arr,n-1);
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Entre The Number: ";
        cin>>arr[i];
    }
    cout<<sumofall(arr,n-1);
}