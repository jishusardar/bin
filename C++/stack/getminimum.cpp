//get minimum at pop
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int>st;
void adjust(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++){
        if(st.empty())
        st.push(arr[i]);
        else
        st.push(min(st.top(),arr[i]));
    }
}
int pope()
{
    if(st.empty())
    cout<<"Stack Overflow";
    else{
        int el=st.top();
        st.pop();
        return st.top();
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Eleement: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    adjust(arr);
    while(!st.empty()){
        cout<<pope();
    }
}