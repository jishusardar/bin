//
// Created by jishu on 31-03-2026.
//segment Tree max sum
#include<iostream>
#include <vector>
using namespace std;
class SegmentTree {
    vector<int>tree;
    vector<int>arr;
    int n;
    void build(int node,int start,int end) {
        if (start==end) {
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,end);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    int querryselector(int node,int start,int end,int left,int right) {
        if (left>end||right<start)
            return 0;
        if (start>=left&&end<=right)
            return tree[node];
        int mid=start+(end-start)/2;
        return max(querryselector(2*node+1,start,mid,left,right),querryselector(2*node+2,mid+1,end,left,right));
    }
    void updating(int node,int start,int end,int index,int val) {
        if (index>end||index<start)
            return;
        if (start==end) {
            tree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        updating(2*node+1,start,mid,index,val);
        updating(2*node+2,mid+1,end,index,val);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
public:
    SegmentTree(vector<int>&input) {
        arr=input;
        n=input.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }
    int querry(int left,int right) {
        return querryselector(0,0,n-1,left,right);
    }
    void update(int index,int val) {
        updating(0,0,n-1,index,val);
        arr[index]=val;
    }
};
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    SegmentTree *tree=new SegmentTree(arr);
    cout<<tree->querry(2,5)<<endl;
    tree->update(3,14);
    cout<<tree->querry(2,5);
}
