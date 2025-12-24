// merge sort
#include<iostream>
using namespace std;
void merge(int arr[],int start,int end,int mid)
{
    int temp[(end-start)+1];
    int left=start,right=mid+1,index=0;
    while(left<=mid&&right<=end){
        if(arr[left]<arr[right]){
            temp[index]=arr[left];
            index++,left++;
        }
        else{
            temp[index]=arr[right];
            index++,right++;
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
    for(int i=start;i<=end;i++){
        arr[i]=temp[index];
        index++;
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
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<"Array Before Sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Array After Sorting: "<<endl;
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}