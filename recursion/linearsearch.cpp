//linear sarch using recursion
#include<iostream>
using namespace std;
bool linearsearch(int n,int arr[],int x)
{
    if(n==-1)
    return 0;
    if(arr[n]==x)
    return 1;
    return linearsearch(n-1,arr,x);
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int x;
    cout<<"Entre The Element To Find: ";
    cin>>x;
    cout<<linearsearch(n-1,arr,x);
}