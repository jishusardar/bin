//maximal rechtangle
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maximalrectangle(vector<int>&height)
{
    int ans=0;
    stack<int>st;
    int n=height.size();
    for(int i=0;i<n;i++){
        while(!st.empty()&&height[st.top()]>height[i]){
            int index=st.top();
            st.pop();
            if(!st.empty())
            ans=max(ans,height[index]*(i-st.top()-1));
            else
            ans=max(ans,height[index]*(i));
        }
        st.push(i);
    }
    while(!st.empty()){
        int index=st.top();
        st.pop();
        if(!st.empty())
        ans=max(ans,height[index]*(n-st.top()-1));
        else
        ans=max(ans,height[index]*(n));
    }
    return ans;
}
int main()
{
    vector<vector<int>>arr={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    vector<int>height(arr[0].size(),0);
    int ans=0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0)
            height[j]=0;
            else
            height[i]+=1;
        }
        ans=max(ans,maximalrectangle(height));
    }
    cout<<"Maximal Rectangle is: "<<ans;
}