//first negative integer in every window of size
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> windowofsizek(vector<int>&arr,int k)
{
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    for(int i=k-1;i<arr.size();i++){
        if(arr[i]<0)
        q.push(i);
        if(q.empty())
        ans.push_back(0);
        else{
            if(q.front()<=i-k)
            q.pop();
            if(q.empty())
            ans.push_back(0);
            else
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int k;
    cout<<"Entre The Window Size: ";
    cin>>k;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
    vector<int>ans=windowofsizek(arr,k);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}