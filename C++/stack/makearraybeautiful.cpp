//make array beautiful
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> makearraybeautiful(vector<int>&arr)
{
    stack<int>st;
    st.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]>=0&&st.top()>=0)
        st.push(arr[i]);
        else if(arr[i]<0&&st.top()<0)
        st.push(arr[i]);
        else
        st.pop();
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    vector<int>arr={2,3,5,-4,6,-2,-8,9};
    arr=makearraybeautiful(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}