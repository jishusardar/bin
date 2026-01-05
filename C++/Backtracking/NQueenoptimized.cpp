//
// Created by jishu on 05-01-2026.
//
#include<iostream>
#include <vector>
using namespace std;
void find(int row,vector<vector<string>>&ans,vector<string>&Board,int n,vector<bool>&colm,vector<bool>&left,vector<bool>&right) {
    if (row==n) {
        ans.push_back(Board);
        return;
    }
    for (int j=0;j<n;j++) {
        if (!colm[j]&&!left[(n-1)+(j-row)]&&!right[j+row]) {
            colm[j]=1;
            left[(n-1)+(j-row)]=1;
            right[j+row]=1;
            Board[row][j]='Q';
            find(row+1,ans,Board,n,colm,left,right);
            colm[j]=0;
            left[(n-1)+(j-row)]=0;
            right[j+row]=0;
            Board[row][j]='.';
        }
    }
}
void solveNqueen(int n) {
    vector<bool>colm(n,0);
    vector<vector<string>>ans;
    vector<string>Board(n);
    vector<bool>Leftdiag(2*n-1,0);
    vector<bool>Rightdiag(2*n-1,0);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
            Board[i].push_back('.');
    }
    find(0,ans,Board,n,colm,Leftdiag,Rightdiag);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout<<"Entre The Queen No: ";
    cin>>n;
    solveNqueen(n);
}
