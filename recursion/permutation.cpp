//permutation
// #include<iostream>
// #include<vector>
// using namespace std;
// void permutations(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,vector<int>&visited)
// {
//     if(temp.size()==visited.size()){
//         ans.push_back(temp);
//         return;
//     }
//     for(int i=0;i<visited.size();i++){
//         if(visited[i]==0){
//             temp.push_back(arr[i]);
//             visited[i]=1;
//             permutations(arr,ans,temp,visited);
//             visited[i]=0;
//             temp.pop_back();
//         }
//     }
// }
// vector<vector<int>>dintinctpermutation(vector<int>&arr)
// {
//     vector<vector<int>>ans;
//     vector<int>temp;
//     vector<int>visited(arr.size(),0);
//     permutations(arr,ans,temp,visited);
//     return ans;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     vector<vector<int>>ans=dintinctpermutation(arr);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//permutation by reducing space complexity
#include<iostream>
#include<vector>
using namespace std;
void permute(vector<vector<int>>&ans,vector<int>&arr,int index)
{
    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[i],arr[index]);
        permute(ans,arr,index+1);
        swap(arr[i],arr[index]);
    }
}
vector<vector<int>>permutation(vector<int>&arr)
{
    vector<vector<int>>ans;
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