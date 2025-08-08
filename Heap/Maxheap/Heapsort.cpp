//Heap Sort
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
    for (int i=(n/2)-1;i>=0;i--) {
        Heapify(arr,n,i);
    }
}
void HeapSort(int arr[],int n) {
    BuildMaxHeap(arr,n);
    for (int i=n-1;i>0;i--) {
        swap(arr[i],arr[0]);
        Heapify(arr,i,0);
    }
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int arr[n];
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    HeapSort(arr,n);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
//heap priority queue ke implementation me use hota hai
