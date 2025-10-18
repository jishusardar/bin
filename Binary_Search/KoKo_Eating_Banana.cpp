//koko eating banana
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
int koko_eating_banana(vector<int>&arr,int h) {
    sort(arr.begin(),arr.end());
    int start=0,end=0,ans;
    for (int i=0;i<arr.size();i++) {
        start+=arr[i];
        end=max(end,arr[i]);
    }
    start/=h;
    while (start<=end) {
        int mid=start+(end-start)/2;
        int time=0;
        for (int i=0;i<arr.size();i++) {
            time+=arr[i]/mid;
            if (arr[i]%mid)
                time++;
        }
        if (time>h)
            start=mid+1;
        else {
            ans=mid;
            end=mid-1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The Element: ";
    vector<int>arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int time;
    cout<<"Entre The Time: ";
    cin>>time;
    cout<<koko_eating_banana(arr,time);
}
