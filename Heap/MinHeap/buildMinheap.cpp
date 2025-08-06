//
// Created by jishu on 07-08-2025.
//build min heap
#include <iostream>
using namespace std;
class Minheap {
    int *arr;
    int size;
    int totalsize;
    void Hepify(int index) {
        int smallest=index;
        int left=2*index+1;
        int right=2*index+2;
        if (left<size&&arr[left]<arr[smallest])
            smallest=left;
        if (right<size&&arr[right]<arr[smallest])
            smallest=right;
        if (smallest!=index) {
            swap(arr[smallest],arr[index]);
            Hepify(smallest);
        }
    }
public:
    Minheap(int n) {
        arr=new int[n];
        size=0;
        totalsize=n;
    }
    void insert(int val) {
        if (size==totalsize) {
            cout<<"The Heap overflow \n";
            return;
        }
        cout<<"The Element "<<val<<" is inserted into Hap\n";
        arr[size]=val;
        int index=size;
        size++;
        while (arr[index]<arr[(index-1)/2]) {
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    void Delete() {
        if (size==0) {
            cout<<"The Heap underflow \n";
            return;
        }
        cout<<"The Element "<<arr[0]<<" is Deleted from Heap \n";
        arr[0]=arr[size-1];
        size--;
        if (size==0)
            return;
        Hepify(0);
    }
    void printall() {
        for (int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    Minheap* h1=new Minheap(6);
    h1->insert(34);
    h1->insert(56);
    h1->insert(90);
    h1->insert(8);
    h1->Delete();
    h1->Delete();
    h1->printall();
}
