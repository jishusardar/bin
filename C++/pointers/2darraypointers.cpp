//2d array pointers
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Entre The Row and Colm: ";
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        *(arr+i)=new int[m];
    }
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            *(*(arr+i)+j)=++num;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }

}