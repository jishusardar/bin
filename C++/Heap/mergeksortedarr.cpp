//
// Created by Jishu Sardar on 19/08/25.
//merge k sorted array
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&arr,int start,int end,int mid) {
    vector<int>temp(end-start+1);
    int left=start,right=mid+1,index=0;
    while(left<=mid&&right<=end){
        if(arr[left]>arr[right]){
            temp[index]=arr[right];
            right++,index++;
        }
        else{
            temp[index]=arr[left];
            left++,index++;
        }
    }
    while(left<=mid){
        temp[index]=arr[left];
        left++,index++;
    }
    while(right<=end){
        temp[index]=arr[right];
        right++,index++;
    }
    index=0;
    for(int i=start;i<=end;i++){
        arr[i]=temp[index++];
    }
}
void mergesort(vector<int>&arr,int start,int end,int portion,int k) {
    if (portion<2)
        return;
    int mid=start+(portion/2)*k-1;
    mergesort(arr,start,mid,portion/2,k);
    mergesort(arr,mid+1,end,portion-portion/2,k);
    merge(arr,start,end,mid);
}
vector<int> mergeksortedarray(vector<vector<int> >&mat) {
    vector<int>ans;
    for (int i=0;i<mat.size();i++) {
        for (int j=0;j<mat[0].size();j++)
            ans.push_back(mat[i][j]);
    }
    mergesort(ans,0,ans.size()-1,mat.size(),mat.size());
    return ans;
}
int main() {
    int n,m;
    cout<<"Entre The Rows and Colm: ";
    cin>>n>>m;
    vector<vector<int> >arr(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<"Entre The Element: ";
            cin>>arr[i][j];
        }
    }
    vector<int>ans=mergeksortedarray(arr);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}