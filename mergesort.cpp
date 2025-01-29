//merge sort
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int start,int end,int mid)
{
    vector<int>temp(end-start+1);
    int left=start;
    int right=mid+1;
    int index=0;
    while(left<=mid&&right<=end){
        if(arr[left]>arr[right]){
            temp[index]=arr[right];
            index++,right++;
        }
        else{
            temp[index]=arr[left];
            left++,index++;
        }
    }
    while(left<=mid){
        temp[index]=arr[left];
        index++,left++;
    }
    while(right<=end){
        temp[index]=arr[right];
        index++,right++;
    }
    index=0;
    while(start<=end){
        arr[start]=temp[index];
        start++,index++;
    }
}
void mergesort(int arr[],int start,int end)
{
    if(start>=end)
    return;
    int mid=start+(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end,mid);
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Entre The Elment: ";
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
