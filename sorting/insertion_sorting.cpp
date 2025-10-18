//
// Created by jishu on 18-10-2025.
//insertion Sort
#include<iostream>
#include <vector>
using namespace std;
void insertion_sort(vector<int>&arr) {
    for (int i=0;i<arr.size()-1;i++) {
        int num=arr[i];
        int index=i;
        for (int j=i+1;j<arr.size();j++) {
            if (arr[j]<num) {
                num=arr[j];
                index=j;
            }
        }
        swap(arr[index],arr[i]);
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr);
    for (int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }

}
