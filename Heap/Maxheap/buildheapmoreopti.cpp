//
// Created by jishu on 08-08-2025.
//Build Max Heap in time complexity O(N)
//using stepdown approach comparing parent with childrens
#include <iostream>
using namespace std;
void Heapify(int arr[],int n,int index) {
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if (left<n&&arr[left]>arr[largest])
        largest=left;
    if (right<n&&arr[right]>arr[largest])
        largest=right;
    if (largest!=index) {
        swap(arr[largest],arr[index]);
        Heapify(arr,n,largest);
    }
}
void BuildMaxHeap(int arr[],int n) {
    for (int i=n/2-1;i>=0;i--) {
        Heapify(arr,n,i);
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    BuildMaxHeap(arr,n);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
