//string manupulation
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<string> stringmanupulation(vector<string>&arr)
{
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        if(!st.empty()&&arr[i]==arr[st.top()])
        st.pop();
        else
        st.push(i);
    }
    vector<string>ans;
    while(!st.empty()){
        ans.push_back(arr[st.top()]);
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<string>arr={"ab","ac","da","da","ac","db","ea"};
    arr=stringmanupulation(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}