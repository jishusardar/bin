// target sums
#include<iostream>
#include<vector>
using namespace std;
bool targetsums(vector<int>&arr,int i,int n,int sum)
{

    if(sum==0)
    return 1;
    if(sum<0||i==n)
    return 0;
    return targetsums(arr,i+1,n,sum)||targetsums(arr,i+1,n,sum-arr[i]);
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int sums;
    cout<<"Entre The Target: ";
    cin>>sums;
    if(targetsums(arr,0,n,sums))
    cout<<"The Target sums is Valid";
    else
    cout<<"The Target sums is not valid";
}