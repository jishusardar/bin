//perfect sums
#include<iostream>
#include<vector>
using namespace std;
bool perfectsums(vector<int>&arr,int i,int n,int sums)
{
    if(sums==0)
    return 1;
    if(sums<0||i==n)
    return 0;
    return perfectsums(arr,i+1,n,sums)||perfectsums(arr,i+1,n,sums-arr[i]);
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
    cout<<"Entre The Sum: ";
    cin>>sums;
    if(perfectsums(arr,0,n,sums))
    cout<<"The Sums are perfect";
    else
    cout<<"The Sums are not perfect";
}