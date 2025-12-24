//
// Created by jishu on 14-08-2025.
//heap creation
#include <iostream>
#include <vector>
using namespace std;
class Maxheap {
    int *arr;
    int size;
    int totalsize;
public:
    Maxheap(int n) {
        totalsize=n;
        size=0;
        arr=new int[n];
    }
    void insert(int data) {
        if (size>totalsize) {
            cout<<"Heap Overflow";
            return;
        }
        arr[size]=data;
        int index=size;
        size++;
        while (index>0&&arr[(index-1)/2]<arr[index]) {
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    void Delete() {
        if (size==0) {
            cout<<"Heap Underflow";
            return;
        }
        arr[0]=arr[size-1];
        cout<<"The Number "<<arr[0]<<" is deleted From The Heap";
        size--;
        if (size==0)
            return;
        Heapify(0);
    }
    void printall() {
        for (int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
    }
    void Heapify(int index) {
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if (left<totalsize&&arr[left]>arr[largest])
            largest=left;
        if (right<totalsize&&arr[right]>arr[largest])
            largest=right;
        if (largest!=index) {
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }
    }
};
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elements: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    Maxheap* m1=new Maxheap(n);
    for (int i=0;i<arr.size();i++) {
        m1->insert(arr[i]);
        m1->Delete();
    }
    m1->printall();
}
