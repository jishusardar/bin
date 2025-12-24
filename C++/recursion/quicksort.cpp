//quick sort
#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
    int i=start,j=end,pivot=arr[start];
    while(i<j){
        while(arr[i]<=pivot&&i<=end-1)
        i++;
        while(arr[j]>pivot&&j>=start-1)
        j--;
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[start],arr[j]);
    return j;
}
void quicksort(int arr[],int start,int end)
{
    if(start>=end)
    return;
    int pos=partition(arr,start,end);
    quicksort(arr,start,pos-1);
    quicksort(arr,pos+1,end);
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
    quicksort(arr,0,n-1);
    cout<<"Array After Sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}