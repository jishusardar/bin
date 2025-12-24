//sliding window maximum
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int>slidingwindowmaximum(vector<int>&arr,int k)
{
    vector<int>ans;
    deque<int>dq;
    for(int i=0;i<k-1;i++){
        if(dq.empty())
        dq.push_back(i);
        else{
            while(!dq.empty()&&arr[i]>arr[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
    }
    for(int i=k-1;i<arr.size();i++){
        while(!dq.empty()&&arr[i]>arr[dq.back()])
        dq.pop_back();
        dq.push_back(i);
        while(dq.front()<=i-k)
        dq.pop_front();
        ans.push_back(arr[dq.front()]);
    }
    return ans;
}
int main()
{
    int n,k;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The K: ";
    cin>>k;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>ans=slidingwindowmaximum(arr,k);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}