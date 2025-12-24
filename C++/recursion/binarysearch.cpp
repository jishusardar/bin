//binary search
#include<iostream>
using namespace std;
bool binarysearch(int arr[],int start,int end,int x)
{
    if(start>=end)
    return 0;
    int mid=start+(end-start)/2;
    if(arr[mid]==x)
    return 1;
    else if(arr[mid]>x)
    return binarysearch(arr,start,mid-1,x);
    else
    return binarysearch(arr,mid+1,end,x);
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
    cout<<"Entre The Element to find: ";
    cin>>x;
    cout<<binarysearch(arr,0,n-1,x);
}