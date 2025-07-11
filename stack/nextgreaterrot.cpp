//next greater rotated array
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>nextgreaterroated(vector<int>&arr)
{
    stack<int>st;
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<2*arr.size();i++){
        while(!st.empty()&&arr[i%arr.size()]>arr[st.top()%arr.size()]){
            ans[st.top()%arr.size()]=arr[i%arr.size()];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()%arr.size()]=-1;
        st.pop();
    }
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
}