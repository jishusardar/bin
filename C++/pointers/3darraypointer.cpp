//3d array using pointer
#include<iostream>
using namespace std;
int main()
{
    int n,m,h;
    cout<<"Entre The Row: ";
    cin>>n;
    cout<<"Entre The Column: ";
    cin>>m;
    cout<<"Entre The Height: ";
    cin>>h;
    int ***arr=new int**[n];
    for(int i=0;i<n;i++){
        arr[i]=new int*[m];
        for(int j=0;j<m;j++){
            arr[i][j]=new int[h];
        }
    }
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;j<h;k++){
                arr[i][j][k]=++num;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<h;k++){
                cout<<arr[i][j][k]<<" ";
            }
        }
    }
}