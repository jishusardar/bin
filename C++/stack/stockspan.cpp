//stock span problem
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> stockspan(vector<int>&arr)
{
    stack<int>st;
    vector<int>ans(arr.size(),1);
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty()&&arr[i]>arr[st.top()]){
            ans[st.top()]=st.top()-i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    arr=stockspan(arr);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
}