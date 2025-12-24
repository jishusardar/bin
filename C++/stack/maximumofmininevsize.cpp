//maximum of minimum of every window size
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> maximumofminwinsize(vector<int>&arr)
{
    int n=arr.size();
    vector<int>ans(n,0);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[i]<arr[st.top()]){
            int index=st.top();
            st.pop();
            if(st.empty()){
                int range=i;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
            else{
                int range=i-st.top()-1;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
        }
        st.push(i);
    }
    while(!st.empty()){
        int index=st.top();
        st.pop();
        if(st.empty()){
            int range=n;
            ans[range-1]=max(ans[range-1],arr[index]);
        }
        else{
            int range=n-st.top()-1;
            ans[range-1]=max(ans[range-1],arr[index]);
        }
    }
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i+1],ans[i]);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    vector<int>ans=maximumofminwinsize(arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}