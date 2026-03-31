// Created by jishu on 30-03-2026
//segment Tree Implementation
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
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    void updating(int node,int start,int end,int index,int val) {
        if (index>end||start>index)
            return;
        if (start==end) {
            tree[node]=val;
            return;
        }
        tree[node]+=val-arr[index];
        int mid=start+(end-start)/2;
        //left child
        updating(2*node+1,start,mid,index,val);
        //right child
        updating(2*node+2,mid+1,end,index,val);
    }
public:
    SegmentTree(vector<int>&input) {
        arr=input;
        n=input.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }
    int querry(int left,int right) {
        return queryselector(0,0,n-1,left,right);
    }
    int queryselector(int node,int start,int end,int left,int right) {
        //fully out of range
        if (left>end||start>right)
            return 0;
        if (left<=start&&end<=right)
            return tree[node];
        int mid=start+(end-start)/2;
        return queryselector(2*node+1,start,mid,left,right)+queryselector(2*node+2,mid+1,end,left,right);
    }
    void update(int index,int value) {
        return updating(0,0,n-1,index,value);
    }

};
int main() {
    int n;
    cout<<"Entre The No of Element: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    SegmentTree* tree=new SegmentTree(arr);
    cout<<tree->querry(2,3)<<endl;
    tree->update(2,3);
    cout<<tree->querry(2,3);
}
