//insert at bottom
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int> inserttobottom(stack<int>st,int num)
{
    stack<int>ans;
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    st.push(num);
    while(!ans.empty()){
        st.push(ans.top());
        ans.pop();
    }
    return st;
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
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        st.push(arr[i]);
    }
    int num;
    cout<<"Entre The Number: ";
    cin>>num;
    st=inserttobottom(st,num);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}