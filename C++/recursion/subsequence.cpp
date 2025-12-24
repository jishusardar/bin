//subsequence
#include<iostream>
#include<vector>
using namespace std;
void sequence(vector<int>&arr,vector<vector<int>>&ans,vector<int>temp,int i)
{
    if(i==arr.size()){
        ans.push_back(temp);
        return;
    }
    sequence(arr,ans,temp,i+1);
    temp.push_back(arr[i]);
    sequence(arr,ans,temp,i+1);
}
vector<vector<int>> subquence(vector<int>&arr)
{
    vector<vector<int>>ans;
    vector<int>temp;
    sequence(arr,ans,temp,0);
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
    vector<vector<int>>ans=subquence(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}