//next smaller on right
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextsmaller(vector<int>&arr)
{
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[i]<arr[st.top()]){
            arr[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        arr[st.top()]=-1;
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
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    nextsmaller(arr);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}