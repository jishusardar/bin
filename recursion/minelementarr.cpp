//min element in the array
#include<iostream>
#include<climits>
using namespace std;
int minelement(int n,int arr[])
{
    if(n==0)
    return arr[0];
    return min(arr[n],minelement(n-1,arr));
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
    cout<<minelement(n-1,arr);
}