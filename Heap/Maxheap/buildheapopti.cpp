//
// Created by jishu on 08-08-2025.
//build max heap in time complexity O(nlongn)
//using step up approach where comparing child with parents
#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int>&arr,int index) {
    while (arr[index]>arr[(index-1)/2]&&index<arr.size()) {
        swap(arr[index],arr[(index-1)/2]);
        index=(index-1)/2;
    }
}
void BuildMaxHeap(vector<int>&arr) {
    for (int i=1;i<arr.size();i++) {
        Heapify(arr,i);
    }
}
int main() {
    int n;
    cout<<"EnTre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    BuildMaxHeap(arr);
    for (int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
