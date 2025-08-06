//
// Created by jishu on 07-08-2025.
//build max heap
#include <iostream>
#include <vector>
using namespace std;
class Maxheap {
    int *arr;
    int size;
    int totalsize;
public:
    Maxheap(int n) {
        arr=new int[n];
        size=0;
        totalsize=n;
    }
    void insert(int val) {
        if (size==totalsize) {
            cout<<"Max Heap Overflow \n";
            return;
        }
        cout<<"The Element is "<<val<<" is inserted into heap\n";
        arr[size]=val;
        int index=size;
        size++;
        while(arr[index]>arr[(index-1)/2]&&index>0) {
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    void Delete() {
        if (size==0) {
            cout<<"Max Heap Underflow\n";
            return;
        }
        cout<<"The Element is "<<arr[0]<<" is deleted from heap \n";
        arr[0]=arr[size-1];
        size--;
        if (size==0)
            return;
        Heapify(0);
    }
    void Heapify(int index) {
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if (left<size&&arr[left]>arr[largest])
            largest=left;
        if (right<size&&arr[right]>arr[largest])
            largest=right;
        if (largest!=index) {
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }
    }
    void printall() {
        for (int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    Maxheap* m1=new Maxheap(4);
    m1->insert(23);
    m1->insert(34);
    m1->insert(90);
    m1->insert(35);
    m1->Delete();
    m1->Delete();
    m1->Delete();
    m1->Delete();
    m1->printall();
}
