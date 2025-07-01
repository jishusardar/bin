//rate in a maze backtracking problem
#include<iostream>
#include<vector>
using namespace std;
string dir="UDLR";
int arr1[4]={-1,1,0,0};
int arr2[4]={0,0,-1,1};
bool valid(int i,int j,int n,int m)
{
    if(i>=0&&j>=0&&i<n&&j<m)
    return 1;
    return 0;
}
void Total(vector<string>&ans,string temp,int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<bool>>&visited)
{
    if(i==n-1&&j==m-1){
        ans.push_back(temp);
        return;
    }
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        if(valid(i+arr1[k],j+arr2[k],n,m)&&mat[i+arr1[k]][j+arr2[k]]&&!visited[i+arr1[k]][j+arr2[k]]){
            temp.push_back(dir[k]);
            Total(ans,temp,i+arr1[k],j+arr2[k],n,m,mat,visited);
            temp.pop_back();
        }
    }

}
vector<string> allposiiblepaths(vector<vector<int>>&mat)
{
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    string path;
    vector<string>ans;
    int i=0,j=0;
    Total(ans,path,i,j,n,m,mat,visited);
    return ans;
}
int main()
{
    vector<vector<int>>mat={{1,0,0,0},{1,1,0,1},{1,1,1,1},{1,1,1,1}};
    vector<string>ans=allposiiblepaths(mat);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}