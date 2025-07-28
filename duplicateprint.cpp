//
// Created by jishu on 26-07-2025.
//
#include <iostream>
using namespace std;
int duplicate(int arr[],int n) {
    int ans=0;
    int ans2=0;
    for (int i=0;i<n;i++) {
        ans^=arr[i];
    }
    for (int i=1;i<n;i++) {
        ans2^=arr[i];
    }
    return ans^ans2;
}
int main() {
    int n;
    cout<<"Size: ";
    cin>>n;
    int arr[n];
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<duplicate(arr,n);

}
