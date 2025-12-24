//
// Created by jishu on 15-08-2025.
//Mergetwo binary Search tree max heap
#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int>&arr,int index,int n) {
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if (left<n&&arr[left]>arr[largest])
        largest=left;
    if (right<n&&arr[right]>arr[largest])
        largest=right;
    if (largest!=index) {
        swap(arr[index],arr[largest]);
        Heapify(arr,largest,n);
    }
}
void BuildmaxHeap(vector<int>&ans) {
    int n=ans.size();
    for (int i=(n/2)-1;i>=0;i--) {
        Heapify(ans,i,n);
    }
}
vector<int> MergeTwoBSTintomaxHeap(vector<int>&a,vector<int>&b) {
    vector<int>ans;
    for (int i=0;i<a.size();i++)
        ans.push_back(a[i]);
    for (int i=0;i<b.size();i++)
        ans.push_back(b[i]);
    BuildmaxHeap(ans);
    return ans;
}
int main() {
    int n,m;
    cout<<"Entre The Size: ";
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    cout<<"Entre The Element a: ";
    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Entre The Elements b: ";
    for (int i=0;i<m;i++)
        cin>>b[i];
    vector<int>ans=MergeTwoBSTintomaxHeap(a,b);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
