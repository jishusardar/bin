//Next greater on right
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextgreater(vector<int>&arr)
{
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[i]>arr[st.top()]){
            arr[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    nextgreater(arr);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
}