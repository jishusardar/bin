//find minimum in rotated array
#include<iostream>
#include <vector>
using namespace std;
int Find_Minimum(vector<int>&nums) {
    int start=0,end=nums.size()-1,ans=-1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (nums[mid]>=nums[0])
            start=mid+1;
        else {
            ans=nums[mid];
            end=mid-1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Find_Minimum(arr);
}
