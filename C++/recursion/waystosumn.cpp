// ways to sum n
#include<iostream>
#include<vector>
using namespace std;
int ways(vector<int>&arr,int sum)
{
    if(sum==0)
    return 1;
    if(sum<0)
    return 0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans+=ways(arr,sum-arr[i]);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int sum;
    cout<<"Entre The Sum: ";
    cin>>sum;
    cout<<ways(arr,sum);
}