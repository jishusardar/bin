//largest rectangle in histogram
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int largestrectangle(vector<int>&arr)
{
    int ans=0;
    stack<int>st;
    int n=arr.size();
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>arr[i]){
            int index=st.top();
            st.pop();
            if(!st.empty())
            ans=max(ans,arr[index]*(i-st.top()-1));
            else
            ans=max(ans,arr[index]*(i));
        }
        st.push(i);
    }
    while(!st.empty()){
        int index=st.top();
        st.pop();
        if(!st.empty())
        ans=max(ans,arr[index]*(n-st.top()-1));
        else
        ans=max(ans,arr[index]*n);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"The Largest Rectangle is Having area is: "<<largestrectangle(arr);
}