//permutation the element is not distinct
#include<iostream>
#include<vector>
using namespace std;
void permute(vector<vector<int>>&ans,vector<int>&arr,int index)
{
    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }
    vector<int>visited(21,0);
    for(int i=index;i<arr.size();i++){
        if(visited[arr[i]+10]==0){
            visited[arr[i]+10]=1;
            swap(arr[i],arr[index]);
            permute(ans,arr,index+1);
            swap(arr[i],arr[index]);
        }
    }
}
vector<vector<int>> permutation(vector<int>&arr)
{
    vector<vector<int>>ans;
    vector<int>temp;
    permute(ans,arr,0);
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
    vector<vector<int>>ans=permutation(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}