#include<iostream>
using namespace std;
int sqrt(int n)
{
    int start=1,end=n;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid==n/mid)
        return mid;
        else if(mid>n/mid)
        end=mid-1;
        else{
        start=mid+1;
        ans=mid;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Number : ";
    cin>>n; 
    cout<<sqrt(n);
}