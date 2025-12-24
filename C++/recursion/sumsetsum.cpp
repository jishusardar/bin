//subset sums
#include<iostream>
#include<vector>
using namespace std;
void sums(vector<int>&arr,vector<int>&ans,int i,int n,int sum)
{
    if(i==n){
        ans.push_back(sum);
        return;
    }
    sums(arr,ans,i+1,n,sum);
    sums(arr,ans,i+1,n,sum+arr[i]);
}
vector<int> subsetsums(vector<int>&arr)
{
    vector<int>ans;
    int sum=0;
    sums(arr,ans,0,arr.size(),sum);
    return ans;
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
    vector<int>ans=subsetsums(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}