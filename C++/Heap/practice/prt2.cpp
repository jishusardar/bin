//
// Created by jishu on 15-08-2025.
//the stepdown method means parent se start hota hai children pe khatam
//time complexity is O(n) more optimized than step up approach which is taking time complexity O(nlog n)
#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int>&arr,int index,int n) {
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if (left<n&&arr[left]>arr[largest])
        largest=left;
    if (right<n&&arr[right]>arr[largest])
        largest=right;
    if (largest!=index) {
        swap(arr[index],arr[largest]);
        Heapify(arr,largest,n);
    }
}
void BuildMaxHeap(vector<int>&arr) {
    for (int i=(arr.size()/2)-1;i>=0;i--) {
        Heapify(arr,i,arr.size());
    }
}
//heap sort a sorting algorithm that has a time complexity of O(nlogn)
void HeapSort(vector<int>&arr) {
    BuildMaxHeap(arr);
    for (int i=arr.size()-1;i>0;i--) {
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    HeapSort(arr);
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
